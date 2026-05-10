#include <bits/stdc++.h>
using namespace std;

int main() {
    int row, col;
    cout << "Enter the row and col: " << endl;
    cin >> row >> col;

    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {

            // minimum distance from any border
            int top = i - 1;
            int left = j - 1;
            int bottom = row - i;
            int right = col - j;

            int layer = min(min(top, bottom), min(left, right));

            // largest number = number of layers
            int value = min(row, col) / 2 + 1 - layer;

            cout << value << " ";
        }
        cout << endl;
    }
}

































// #include<bits/stdc++.h>
// using namespace std;


// int main(){

//      int row;
//      cout <<"Enter the number of rows: ";
//      cin >> row;

//      if(row % 2 == 0) row --;

//       //prining the downward triangle
//       for(int i = 1 ; i <= row ; i++){

//         if(i % 2 != 0){
//           //for space
//           for(int j = 1 ; j < i ; j++){
//             cout <<" ";
//           }
//           for(int k = row ; k >= i ; k--){
//              cout <<"* ";
//           }
//           cout << endl;
//         }

//       }


//       //printing the upward triangle

//       for(int i = 3 ; i <= row ; i++){

//          if(i % 2 != 0){
//             //for the spaces
//             for(int j = row ; j > i ; j -- ){
//                  cout << " ";
//             }

//             //for the values
//             for(int k = 1 ; k <= i ;k++){
//                   cout <<"* ";
//             }
//             cout << endl;

//         }
//       }


// }
























//                          //
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int row;
//     cout << "Enter number of rows (odd recommended): ";
//     cin >> row;
//     cout << endl;

//     if (row % 2 == 0) row--;  // ensure odd rows

//     int maxStars = row; // number of stars in first line

//     // UPPER PART
//     for(int i = 0; i < row; i += 2) {
//         int spaces = i;
//         int stars = maxStars - i;

//         // print spaces
//         for(int s = 0; s < spaces; s++)
//             cout << " ";

//         // print stars
//         for(int st = 0; st < stars; st++)
//             cout << "* ";

//         cout << endl;
//     }

//     // LOWER PART
//     for(int i = row - 3; i >= 0; i -= 2) {
//         int spaces = i;
//         int stars = maxStars - i;

//         // print spaces
//         for(int s = 0; s < spaces; s++)
//             cout << " ";

//         // print stars
//         for(int st = 0; st < stars; st++)
//             cout << "* ";

//         cout << endl;
//     }

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;

// int main(){

//       int row;
//       cout <<"Enter the no of rows: ";
//       cin >> row;

//       cout << endl;

//       for(int i = 1 ; i <= row ; i++){

//         if(i % 2 != 0){

//          for(int j = 1 ; j < i ;j++){
//              cout <<" ";
//          }

//          for(int k = row ; k >= i ; k--){
//              cout << "* ";
//          }
//             cout << endl;
//         }



//       }

//       for(int i = 2 ; i <= row ; i++){

//         if( i % 2 != 0){

//           for(int j = i ; j< row ; j++){
//                cout <<" ";
//           }

//           for(int k = 1 ; k <= i ; k++){
//              cout <<"* ";
//           }
//           cout << endl;

//         }


//       }


// }