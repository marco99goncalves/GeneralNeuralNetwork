#include <bits/stdc++.h>

using namespace std;

int main() {
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++)
            for (int k = 0; k <= 1; k++)
                for (int z = 0; z <= 1; z++) {
                    cout << (((i + j + k + z) % 2 == 0) ? 1 : 0) << ", " << i << ", " << j << ", " << k << ", " << z << "\n";
                }
}