// 03030303030 10827111袁本誠 10827102沈柏融 
#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <time.h>


using namespace std;

bool quit = false;  
clock_t start, end;

typedef struct hibiki{
	string a, b, c, d, e, f, g, h, i, j, k, l;
	int student=0, teacher=0, graduate=0 ;
};


class Mission {
 public:
  void write(string name, vector<struct hibiki> vec){
  	fstream txt;
	txt.open(name.c_str(), ios::out);
    for( int a = 0 ; a < vec.size() ; a++ ) {
    	txt<<vec[a].a, txt<<"\t", txt<<vec[a].b, txt<<"\t", txt<<vec[a].c, txt<<"\t";
		txt<<vec[a].d, txt<<"\t", txt<<vec[a].e, txt<<" ", txt<<vec[a].f, txt<<"\t";
		txt<<vec[a].g, txt<<" ", txt<<vec[a].h, txt<<"\t", txt<<vec[a].student, txt<<"\t";
		txt<<vec[a].teacher, txt<<"\t", txt<<vec[a].graduate, txt<<"\t", txt<<vec[a].i, txt<<" ";
		txt<<vec[a].j, txt<<"\t", txt<<vec[a].k, txt<<" ", txt<<vec[a].l, txt<<"\n";
	}
	txt.close();
  }
  void mission1(){
   string text, bubble, select;
   fstream file;
   cout << "\n" << "Input 501, 502, ...[0]Quit):";
   cin >> text;
   if(text == "0") getcommand(); // 0就是重新輸入指令 
   else {
   	bubble = "bubble" + text + ".txt";
   	select = "select" + text + ".txt";
    text = "input" + text + ".txt";
    file.open(text.c_str(), ios::in);
    if(!file.is_open()) {
     cout << "\n" << "### " << text << " does not exist! ###\n";
     mission1();
    }
    else {
	 string copytemp;
	 for(int b = 0; b != 3 ; b++) getline( file,copytemp );
	 vector<struct hibiki> save, save2;
	 hibiki ouo;
	 while(!file.eof()){
	 	file>>ouo.a, file>>ouo.b, file>>ouo.c, file>>ouo.d, file>>ouo.e, file>>ouo.f;
	 	file>>ouo.g, file>>ouo.h, file>>ouo.student, file>>ouo.teacher, file>>ouo.graduate;
		file>>ouo.i, file>>ouo.j, file>>ouo.k, file>>ouo.l;
	 	save.push_back(ouo);
	 }
	 
	 save2.assign( save.begin(), save.end() );

     // 選擇排序 
	 
	 start = clock();
	 for(int a = 0; a < save.size()-1 ;a++){
	 	for(int b = a+1; b<save.size();b++){
	 		if(save[a].graduate < save[b].graduate) swap(save[a],save[b]);
		}
     }
	 end = clock();
	 write(select, save);
	 cout<<"ouo";
	 /*
	 fstream sel;
     sel.open(select.c_str(), ios::out);
     for( int a = 0 ; a < save.size() ; a++ ) {
     	sel<<save[a].a, sel<<"\t", sel<<save[a].b, sel<<"\t", sel<<save[a].c, sel<<"\t";
		sel<<save[a].d, sel<<"\t", sel<<save[a].e, sel<<" ", sel<<save[a].f, sel<<"\t";
		sel<<save[a].g, sel<<" ", sel<<save[a].h, sel<<"\t", sel<<save[a].student, sel<<"\t";
		sel<<save[a].teacher, sel<<"\t", sel<<save[a].graduate, sel<<"\t", sel<<save[a].i, sel<<" ";
		sel<<save[a].j, sel<<"\t", sel<<save[a].k, sel<<" ", sel<<save[a].l, sel<<"\n";
	 }
	 */
	 
	 /* 
	 int a = save.size();
	 for( int b = 0 ; b < a ; b++){
	 	cout << save[b].graduate << endl; 
	 } // 測試沒存錯 
	 */ 
	 
	 // 泡泡排序 
	 
	 start = clock();
	 for( int a=save2.size() ; a != 1 ; a-- ) {
	 	for( int b=0 ; b < a ; b++) {
	 		if( save2[b].graduate < save2[b+1].graduate ) swap(save2[b], save2[b+1]);
		}
	 }
	 end = clock();
	 cout<<"ouo";
	 write(bubble, save2);
	 /*
	 bub.open(bubble.c_str(), ios::out);
     for( int a = 0 ; a < save.size() ; a++ ) {
     	bub<<save[a].a, bub<<"\t", bub<<save[a].b, bub<<"\t", bub<<save[a].c, bub<<"\t";
		bub<<save[a].d, bub<<"\t", bub<<save[a].e, bub<<" ", bub<<save[a].f, bub<<"\t";
		bub<<save[a].g, bub<<" ", bub<<save[a].h, bub<<"\t", bub<<save[a].student, bub<<"\t";
		bub<<save[a].teacher, bub<<"\t", bub<<save[a].graduate, bub<<"\t", bub<<save[a].i, bub<<" ";
		bub<<save[a].j, bub<<"\t", bub<<save[a].k, bub<<" ", bub<<save[a].l, bub<<"\n";
	 }
	 */
	 
	 
	 
	 
	 
	 
	 
       
  





	 
	 
	 
	 
	 /*
     fstream copy;
	 int total = 0;
     copy.open(copyname.c_str(), ios::out);
     while( !file.eof() ){
       getline( file,copytemp );
       if (copytemp != "\0") {
       	copy << copytemp << "\n";
       	total++;
	   }
	 }
	 
	 cout<<"Number of records = "<< total <<endl;
     */
    
   } 
  }
  } 
  
  void mission2(){
  	fstream list;
  	string name;
  	cout << "\n" << "Input 201, 202, ...[0]Quit):";
  	cin>>name;
  	if(name == "0") getcommand();
  	else {
    	name = "copy" + name + ".txt";
    	int size2 = name.size();
        char listname[size2];
    	for(int a = 0 ; a <= size2 ; a++ ) listname[a] = name[a];
    	list.open(listname, ios::in);
  	    if(!list.is_open()) {
            cout << "\n" << "### " << name << " does not exist! ###\n";
            mission2();
        }
        else{
            vector<string> save;
            string temp1;
       		int end = 0;
     		while(!list.eof()) {
     			getline( list,temp1 );
      			save.push_back(temp1+"\n");
	 		} // while
     		int num1, num2, find = 0;
    		int size3 = save.size() - 2;
    		int number=0, student = 0, graduate = 0;
	 		int result = 0;
     		bool assign = false;
     		//cout<<size3;
     		//for(int f = 0 ; f<=15 ; f++)cout<< "!!" << save[f]; 
    		cout <<"\n" << "Input a lower bound on the number of students:" ;
    		cin>>num1;
    		cout << "\n" << "Input a lower bound on the number of graduates:" ;
    		cin>>num2;
     		ofstream list(listname, ios::trunc);
    		for(int a = 0 ; a <= size3 ; a++) {
    			temp1 = save[a];
     			for(int b = 0 ; b<=temp1.size() ; b++) {
     				if(temp1[b] == '\t')find++;
     				if(find==6){
     					b++;
     					while(temp1[b] != '\t') {
     						//cout<<"("<<temp1[b]<< ")";
     						if ( temp1[b] >= '0' && temp1[b] <= '9' ) {
     						    number = temp1[b] - '0';
     							student = student*10 + number;	
							} // 防"1,078"這種垃圾東西 
     						b++;
						} // 把在學人數給搞出來 
						find++;
						//cout<<student<<"   ";
					} // 找到第6個tap時就是找到在學人數 
     				else if(find==8){
     					b++;
     					while(temp1[b] != '\t') {
     						if ( temp1[b] >= '0' && temp1[b] <= '9' ) {
     							number = temp1[b] - '0';
     							graduate = graduate*10 + number;
     						} // 防"1,078"這種垃圾東西 
     						b++;
						} // 把畢業人數搞出來 
     					find++;
     					assign = true;
     					//cout<<graduate<<endl;
					} //  找到第8個tap時就是找到畢業人數 
					//if (student >= num1)cout<< student << "大於" << num1<<endl;
					//if (graduate >= num2)cout<< graduate << ">=" << num2<<endl;
					if ( assign == true && student >= num1 && graduate >= num2) {
						list<<save[a];
						result++;
						break;
					}
				}
				student = 0, find = 0, graduate = 0;
				assign = false;
	 		}
	 		cout<<"Number of records = "<< result <<endl;
    	}	
   }
  }
  
  void mission3(){
      ;
  }
  
  void getcommand(){ //做1或2或3的指令 
   int choice;
   cout << "\n" ;
    printf("*** File Object Manipulator  ***\n");
    printf("* 0. Quit                      *\n");
    printf("* 1. Copy (Read & Save a file) *\n");
    printf("* 2. FILTER (Reduce a file)    *\n");
    printf("********************************\n");
    printf("Input a choice(0, 1, 2): ");
    cin >> choice;
    if(choice == 1) mission1();
    else if(choice == 2) mission2();
    else if(choice == 3) mission3();
    else if(choice == 0) quit = true;
    else;
  }
};

int main(){
 Mission mission ;
 mission.getcommand();
  while(!quit){
   mission.getcommand();
  }
 
  system("pause");
  return 0;
}


/*
     while(!list.eof()) {
      list >> test;
      if (end==14) {
      	save.push_back(test+"\n");
      	end = -1;
	  }
      else save.push_back(test+"\t");
      //cout<<test<<endl;
      //cout<<save[a];
      a++;
      end++;
	 } // while
*/	 
