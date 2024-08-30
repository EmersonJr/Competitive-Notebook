#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl "\n"
#define ff first
#define ss second
#define input(x) for (auto &it : x) cin >> it;
#define output(x) for (auto &it : x) cout << it << ' ';
#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int INF = INT64_MAX;
const long double PI = acos(-1);
const int MAX = (1e6) + 1;
const int MOD = 998244353;
const int LOG = 30;

//  allows us to multiply two polynomials of length  $n$  in  $O(n \log n)$  time

using cd = complex<double>;

// FFT (usei na H da mineira de 2024 de contar os quadrados)

void fft(vector<cd> &A, bool invert) {
  int N = size(A);

  for (int i = 1, j = 0; i < N; i++) {
    int bit = N >> 1;
    for (; j & bit; bit >>= 1)
      j ^= bit;
    j ^= bit;

    if (i < j)
      swap(A[i], A[j]);
  }

  for (int len = 2; len <= N; len <<= 1) {
    double ang = 2 * PI / len * (invert ? -1 : 1);
    cd wlen(cos(ang), sin(ang));
    for (int i = 0; i < N; i += len) {
      cd w(1);
      for (int j = 0; j < len/2; j++) {
        cd u = A[i+j], v = A[i+j+len/2] * w;
        A[i+j] = u + v;
        A[i+j+len/2] = u-v;
        w *= wlen;
      }
    }
  }

  if (invert) {
    for (auto &x : A)
      x /= N;
  }
}

vector<int> multiply(vector<int> const& A, vector<int> const& B) {
  vector<cd> fa(begin(A), end(A)), fb(begin(B), end(B));
  int N = 1;
  while (N < size(A) + size(B))
    N <<= 1;
  fa.resize(N);
  fb.resize(N);

  fft(fa, false);
  fft(fb, false);
  for (int i = 0; i < N; i++)
    fa[i] *= fb[i];
  fft(fa, true);

  vector<int> result(N);
  for (int i = 0; i < N; i++)
    result[i] = round(fa[i].real());
  return result;
}




void solve()
{
	vector<int> A(MAX,0);
	vector<int> B(MAX,0);

	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		// A com os expoentes positivos e B com os expoentes negativos
		A[x] = 1;
		//A[i] é o coeficiente de z^i
		B[MAX-1-x] = 1;
	}

	// MAX-1 é o novo "0"

	//multiply me da o resultado da multiplicação desses dois polinômios
	// C[i] é o coeficiente de x^i
	
	vector<int> C = multiply(A,B);

	return;
}



int32_t main()
{
    sws

    int t = 1;
    //cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}