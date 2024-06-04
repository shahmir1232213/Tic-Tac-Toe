#include <iostream>
using namespace std;

int row_checker(int b[][3]){
	bool flag = false;
	int k = 0;
	int l = 0;
	int store = 0;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 2; j++){
			if(b[i][j] == b[i][j+1]){
				flag = true;
				l = i;
				k = j;
			}
			else {
				flag = false;
				break;	
			}
		}
		if(flag == true){
			break;
		}
	}
	if(flag == false){
		return 0;	
	}
	else{
		store = b[l][k]; 
		return store;
	}
	
}
int col_checker(int b[][3]){
	bool flag = false;
	int k = 0;
	int l = 0;
	int store = 0;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 2; j++){
			if(b[j][i] == b[j+1][i]){
				flag = true;
				l = i;
				k = j;
			}
			else {
				flag = false;
				break;	
			}
		}
		if(flag == true){
			//return flag;	
			break;
		}
	}
	if(flag == false){
		return 0;	
	}
	else{
		store = b[k][l];	
		return store;
	}	
}
bool right_diag_checker(int b[][3]){
	bool flag = false;
	for(int i = 0; i < 2; i++){	
		for(int j = 2; j >= 1; j--){
				if(b[i][j]==b[i+1][j-1]){
					flag = true;
				}
				else flag = false; 
		}
	}
	return flag;

}
bool left_diag_checker(int b[][3]){
	int l,m = 0;
	bool flag = false;
	for(int i = 0; i < 2; i++){	
		for(int j = 0; j < 2; j++){
			if(i == j){
				if(b[i][j]==b[i+1][j+1]){
					flag = true;
					l=i;
					m=j;
				}
				else flag = false; 
			}	
		}
	}
	return flag;
}
void input(int b[][3],int l,int m,int value){
	b[l][m] = value;
}
void checker(int b[][3]){
			int count = 0;
			while(true){
				if(col_checker(b)!=0){
					cout<<"choice "<<col_checker(b) <<" won \n";
					break;	
				}
				count++;
				if(row_checker(b)!=0){
					cout<<"choice "<<row_checker(b) <<" won \n";
					break;
				} 
				count++;
				if(right_diag_checker(b)==true){
					//cout << "won\n";
					cout<<"choice "<<b[0][2] <<" won \n";
					break;	
				}
				count++;
				if(left_diag_checker(b)==true){
					//cout << "won\n";
					cout<<"choice "<<b[0][0] <<" won \n";
					break;
				} 
				count++;
				
				 if(count==4){
					cout << "draw\n";
					break;
				}
			}
		
}
int main()
{
	cout <<endl;
	cout << "    |     |    \n";
	cout << "00  |01   |02\n";
	cout << "____|_____|____\n";
	cout << "    |     |    \n";
	cout << "10  |11   |12\n";
	cout << "____|_____|____\n";
	cout << "    |     |    \n";
	cout << "20  |21   |22\n";
	cout << "    |     |    \n";
	cout << endl << endl;

	
	int b[3][3] ={};
	int row = 0;
	int col = 0;
	int choice = 0;
	int value = 0;
	while(true){
		cout <<"Press 1 to continue\nPress 2 to exit\nPress 4 to view the indexing\n";
		cout << "After completing game press 3 to check winning \n";
		cin >> choice;
		if(choice==1){
		cout << "Enter row index \n";
		cin >> row;
		cout << "Enter and coloumn \n";
		cin >> col;
//		cout<<"Enter position index: \n";
//		cin >> row >> col;
		cout << "Enter value: \n";
		cin >> value;
		input(b,row,col,value);
		}
		else if(choice == 2)break;
		else if(choice==3){
			checker(b);
			cout << " Thanks For Playing !\n Press 9 to play gaain\n";
			cin >> choice;
			if(choice==9){
				for(int i = 0; i < 3; i ++){
					for(int j = 0; j < 3; j ++){
						b[i][j] = 0;
					}
				}
			}
		}
		else if(choice == 4){
			cout <<endl;
			cout << "    |     |    \n";
			cout << "00  |01   |02\n";
			cout << "____|_____|____\n";
			cout << "    |     |    \n";
			cout << "10  |11   |12\n";
			cout << "____|_____|____\n";
			cout << "    |     |    \n";
			cout << "20  |21   |22\n";
			cout << "    |     |    \n";
			cout << endl << endl;
		}
		else cout <<"invalid input \n";
		cout<<endl;
		if(choice!=4){
			cout <<"    |     |    \n";
    		cout <<""<<b[0][0]<<"   |"<<b[0][1]<<"    |"<<b[0][2]<<"\n";
    		cout <<"____|_____|____\n";
   	 		cout <<"    |     |    \n";
    		cout <<b[1][0]<<"   |"<<b[1][1]<<"    |"<<b[1][2]<<"\n";
    		cout <<"____|_____|____\n";
    		cout <<"    |     |    \n";
    		cout <<b[2][0]<<"   |"<<b[2][1]<<"    |"<<b[2][2]<<"\n";
    		cout <<"    |     |    \n";	
			cout<<endl;	
		}
			
	}		
	
	return 0;
}
