#include <bits/stdc++.h>
using namespace std;

bool isNumber(string s) {
        int size = s.size();
        if (size == 0) return false;

        
        if (size == 1) {
            if (s[0] == '+' || s[0] == '-' || s[0] == 'e' || s[0] == '.' ||
                s[0] == 'E' || (s[0] >= 'a' && s[0] <= 'z') ||
                (s[0] >= 'A' && s[0] <= 'Z')) {
                return false;
            }
            return true;
        }

        bool digitSeen = false;  
        bool dotSeen = false;    
        bool eSeen = false;      

       
        if (!(s[0] == '+' || s[0] == '-' || (s[0] >= '0' && s[0] <= '9') || s[0] == '.')) {
            return false;
        }
        if (s[0] >= '0' && s[0] <= '9') digitSeen = true;
        if (s[0] == '.') dotSeen = true;

        for (int i = 1; i < size; i++) {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
                if (s[i] != 'e' && s[i] != 'E') return false;
            }

            if (s[i] >= '0' && s[i] <= '9') {
                digitSeen = true;
            }
            else if (s[i] == '.') {
                if (dotSeen || eSeen) return false;
                dotSeen = true;
            }
            else if (s[i] == 'e' || s[i] == 'E') {
                if (eSeen || !digitSeen || i == size - 1) return false;
                eSeen = true;
                digitSeen = false; 
            }
            else if (s[i] == '+' || s[i] == '-') {
                if (s[i - 1] != 'e' && s[i - 1] != 'E') return false;
                if (i == size - 1) return false;
            }
            else {
                return false;
            }
        }

        return digitSeen;
    }

int main()
{

  string s = "53.5e93";

  bool ans = isNumber(s);

  cout << ans << endl;
}

// #include<stdio.h>
// int main(){
//     int row,col,n;
//     printf("Enter row:");
//     scanf("%d",&n);
//     for(row=1;row<n;row++){
//         for(col=1;col<=row;col++){
//             printf("*");
//         }
//         for(col=1;col<=n-row;col++){
//             printf(" ");
//         }
//         for(col=1;col<=n-row;col++){
//             printf(" ");
//         }
//         for(col=1;col<=row;col++){
//             printf("*");
//         }
//         printf("\n");
//     }
//     // printf("\n");

//     for(row = n - 1  ; row >= 1 ; row --){
//           for(col = 1 ; col <= row ; col++){
//               printf("*");
//           }

//           for(col = 1 ; col <= n - row ; col ++){
//               printf(" ");
//           }

//          for(col = 1 ; col <= n - row ; col ++){
//               printf(" ");
//           }

//           for(col = 1 ; col <= row ; col++){
//                 printf("*");
//           }
//           printf("\n");
//     }
// return 0;
// }