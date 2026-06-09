#include <iostream>
using namespace std;

int main(){
    int r;
    int c;
    cin>>r>>c;
    int grid[r][c];;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>grid[i][j];
        }
    }
    int row;
    int col;
    cout<<"Enter the Position of the cell (row and column): ";
    cin>>row>>col;
    int diff[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    int sum = 0 ;
    for(int i=0;i<8;i++){
        int adrow = row + diff[i][0];
        int adcol = col + diff[i][1];
        if(adrow>=0 && adrow<r && adcol>=0 && adcol<c){
            sum+=grid[adrow][adcol];
        }
    }
    cout<<"Sum of adjacent cells: "<<sum;
}