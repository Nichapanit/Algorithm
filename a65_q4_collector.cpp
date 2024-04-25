#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int S[k+1][n+1];
    int P[k+1];
    int m[k+1];
    for(int i = 0; i < k; i++){
        cin >> P[i+1] >> m[i+1];
        for(int j = 0; j < m[i+1]; j++){
            cin >> S[i+1][j+1];
        }
    }
    //Show input
    for(auto a: P){
        cout << a << " ";
        cout << endl;
    }
    for(auto a:m){
        cout << a << " ";
        cout << endl;
    }
    // for(auto r: S){
    //     cout 
    // }
}


#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

using BookBits = bitset<1000>;

struct Seller {
	int set_price;
	double price_per_book;
	BookBits books;
	bool operator< (const Seller& other) const {
		return set_price > other.set_price;
	}
};

size_t n_books;
int n_sellers;
int current_best; // initially from buying from all sellers

vector<Seller> seller;
vector<BookBits> book_suffix; // [0..n_sellers], the last is all 0s

void rec(int s, int sum, BookBits bb) {
	if ((bb | book_suffix[s]).count() < n_books) {
		// bound: we'll never collect all books from the remaining sellers
		return;
	}

	if (s == n_sellers) { // TODO: try (bb.count() == n_books)
		// have all the books, new best sum
		current_best = sum;
	} else {
		// (1) don't buy from s
		rec(s+1, sum, bb);

		// (2) buy from s
		sum += seller[s].set_price;
		if (sum < current_best)
			rec(s+1, sum, bb | seller[s].books);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> n_books >> n_sellers; // global

	seller.resize(n_sellers);

	// input books by sellers, and compute sellers of books
	for (int s {0}; s < n_sellers; s++) {
		int p,m;
		cin >> p >> m;
		seller[s].set_price = p;
		seller[s].price_per_book = static_cast<double>(p) / m;
		current_best += p;

		auto& bb = seller[s].books;
		while (m-- > 0) {
			int b;
			cin >> b;
			--b;
			bb[b] = 1;
		}
	}

	sort(seller.begin(), seller.end());

	// compute suffixes for pruning when we know that we won't have all the books
	// even after buying from all the remaining sellers
	book_suffix.resize(n_sellers + 1);
	for (int s {n_sellers}; --s >= 0; )
		book_suffix[s] = book_suffix[s+1] | seller[s].books;

	// for each seller, we either buy or don't buy from them
	rec(0, 0, 0);

	cout << current_best;

	return 0;
}
