#include<iostream>
using namespace std;
string s1;
string s2;
string name;
char token;
char arr[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
void board(){
    cout<<"               "<<endl;
    cout<<"               "<<endl;
    cout<<"                TIC TAC TOE        "<<endl;
    cout<<"               _ _ _ _ _ _ _        "<<endl;
    cout<<"               "<<endl;
    
    cout<<"               "<<"   |    |   "<<endl;
    cout<<"               "<<" "<<arr[0][0]<<" |  "<<arr[0][1]<<" |  "<<arr[0][2]<<endl;
    cout<<"               "<<"___|____|___"<<endl;
    cout<<"               "<<"   |    |   "<<endl;
    cout<<"               "<<" "<<arr[1][0]<<" |  "<<arr[1][1]<<" |  "<<arr[1][2]<<endl;
    cout<<"               "<<"___|____|___"<<endl;
    cout<<"               "<<"   |    |   "<<endl;
    cout<<"               "<<" "<<arr[2][0]<<" |  "<<arr[2][1]<<" |  "<<arr[2][2]<<endl;
    cout<<"               "<<"   |    |   "<<endl;

}
/*void assign(){
    if(token=='x'){
        cout<<s1<<" enter the digit"<<endl;
        cin>>digit;
    }
    if(token=='o'){
        cout<<s2<<" enter the digit"<<endl;
        cin>>digit;
    }
    
    if(digit==1){
        row=0;
        column=0;
    }
    if(digit==2){
        row=0;
        column=1;
    }
    if(digit==3){
        row=0;
        column=2;
    }
    if(digit==4){
        row=1;
        column=0;
    }
    if(digit==5){
        row=1;
        column=1;
    }
    if(digit==6){
        row=1;
        column=2;
    }
    if(digit==7){
        row=2;
        column=0;
    }
    if(digit==8){
        row=2;
        column=1;
    }
    if(digit==9){
        row=2;
        column=2;
    }
    else{
        cout<<"Invalid"<<endl;
    }
    if(token=='x' && arr[row][column]!='x' &&arr[row][column]!='0'){
        arr[row][column]='x';
        token='0';
    }
    else if(token=='0' && arr[row][column]!='x' &&arr[row][column]!='0'){
        arr[row][column]='0';
        token='x';
    }
    else{
        cout<<"No Space,Try again";
        assign();
    }



}
*/
bool check() {
    for (int i = 0; i < 3; i++) {
        if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]) {
            return true;
            }
        if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i]){
            return true;
        }
    }
    if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]){
         return true;
         }
    if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]) {
    return true;
    }
    return false;
}
void Move(char player) {
    for(;;) {
        if(player=='X'){
            name=s1;
        }
        if(player=='O'){
            name=s2;
        }
        char move;
        cout <<  name << ", enter your move: "<<endl;
        cin >> move;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (arr[i][j] == move) {
                   arr[i][j] = player;

                    return;
                }
            }
        }
        std::cout << "Invalid move, try again." << endl;
    }
}
int main(){
    cout<<"Player 1 enter your name: "<<endl;
    getline(cin,s1);
    cout<<"Player 2 enter your name: "<<endl;
    getline(cin,s2);
    cout<<s1<<" will start the game..!"<<endl;
    cout<<s1<<" you token is X \n"<<s2<<" your token is O"<<endl;
    board();
    for (int turn = 0; turn < 9; turn++) {
        if(turn%2==0){
            token='X';
        }
        else{
            token='O';
        }
        Move(token);
        board();
        if (check()) {
            cout << "OMG...! " << name<< " wins!" << endl;
            return 0;
        }
    }
    cout << "OOps its a Draw..!" << endl;
    return 0;
    
}
