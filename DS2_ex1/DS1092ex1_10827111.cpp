//10827111 �K���� 
#include <iostream>
#include <fstream> 
#include <string> 
#include <vector> 
#include <ctime>
#include <cstdlib>
#include <math.h> 

using namespace std ;

bool quit = false;

struct data {
	int num ;
    int student = 0 ;

};

struct data2 {
	int num = 0; 
    int student = 0 ;
    int floor = 0;
    string type = "\0" ;
};


class Mission {
    private:
        int listLength, listSize ;    
        int num, floor, student;
        string type = "\0";
        data2 *deal_list;
        data *list ;
    public:
        Mission(){ 
  	        listLength = 10, listSize = 0 ; // allfile �B nowfile	
  	        num = 0;
            student = 0;
            floor = 0;
			type = "\0" ;
            deal_list = new data2[listLength];
            list = new data[listLength];
        }

        void mission1() {
	        string file_number;
  	    	cout << endl << "Input a file number (e.g., 101, 102, 103, ...): ";
  		    cin >> file_number;
  			file_number = "input" + file_number + ".txt";
    		fstream A;
    		A.open( file_number.c_str(), ios::in );
	        
	        if( A.is_open() ) {
        		string temp ;
	        	getline(A,temp);
				getline(A,temp);
				getline(A,temp); // �����e3�� 
				
        	    while( !A.eof() ) {
                    if(listSize == listLength) expansion_ListLength(); 
                    getline( A,temp );
        			if (temp != "\0"){
        			  list[listSize].num = listSize ;
        			  int tap = 1 ;
                      for(int x = 1 ; x <= temp.length() - 1 ; x++ ){
            	        if ( temp[x] == '\t' ) tap++ ;
            	        if ( tap == 7) {
            	        	if (is_number(temp[x])) {
            	        		list[listSize].student = list[listSize].student*10 + (temp[x] - '0' ) ;
            	        		//cout << list[listSize].student << endl;
							} // �Ntxt�ɪ��ǥͼƤ��X�ӡA�é��ʺA�}�C 
						}  
				        
			          }
			          listSize++;
			        }
			        
                    
                }// while
	            
        	} // if( first.is_open() == true )
            else {
                cout << endl << "### " << file_number << " does not exist! ###\n";
                return mission1();
            } // else (file is not exsit)
    
            deal_list = new data2[listSize];
            deal_list[0].num = list[0].num ;
            deal_list[0].student = list[0].student ;

            
            //for(int a = 0; a < listSize-1 ; a++)cout << list[a].student << endl;
            
            //system("PAUSE");
            
        	for(int i = 1; i < listSize; i++){
                deal_list[i].num = list[i].num ;
                deal_list[i].student = list[i].student ;  
            
			    int a = i ;	     
				while( a > 0 ){	
        			if (deal_list[a].student >= deal_list[(a-1)/2].student ) swap(deal_list[a], deal_list[(a-1)/2]) ;
					a = (a-1)/2 ;
        		}      
				
            } // �N���ʺA�}�C������ơA���t�@�}�C�@�̤j��n 
            
            
           
            cout << "<max heap>\n" << "root: [" << deal_list[0].num+1 << "] " << deal_list[0].student << endl ;
            cout << "bottom: [" << deal_list[listSize-1].num+1 << "] " << deal_list[listSize-1].student << endl ;
            int mostleft;
            for(int i = 0; i <= listSize-1 ; i = i*2+1 ) mostleft = i;
            cout << "leftmost bottom: [" << deal_list[mostleft].num+1 << "] " << deal_list[mostleft].student << endl;
            


            deal_list = new data2[listLength];
            list = new data[listLength];
            listSize = 0;
        }
        
        void mission2() {

	        string file_number;
  	    	cout << endl << "Input a file number (e.g., 101, 102, 103, ...): ";
  		    cin >> file_number;
  			file_number = "input" + file_number + ".txt";
    		fstream A;
    		A.open( file_number.c_str(), ios::in );
	        
	        if( A.is_open() == true ) {
        		string temp ;
	        	getline(A,temp); // �����e3 
				getline(A,temp);
				getline(A,temp);
				
        	    while( A.eof() == false ) {
                    if(listSize == listLength) expansion_ListLength(); 
                    getline( A,temp );
        			if (temp != "\0"){
        			  list[listSize].num = listSize+1 ;
        			  int tap = 1 ;
                      for(int x = 1 ; x <= temp.length() - 1 ; x++ ){
            	        if ( temp[x] == '\t' ) tap++ ;
            	        if ( tap == 7) {
            	        	if (is_number(temp[x])) {
            	        		list[listSize].student = list[listSize].student*10 + (temp[x] - '0' ) ;
            	        		//cout << list[listSize].student << endl;
							}
						}  // �Ntxt�ɪ��ǥͼƤ��X�ӡA�é��ʺA�}�C 
				        
			          }
			          //cout << list[listSize].student << endl;
			          //system("pause");
			          listSize++;
			        }
			        
                    
                }// while
	            
        	} // if( first.is_open() == true )
            else {
                cout << endl << "### " << file_number << " does not exist! ###\n";
                return mission2();
            } 
            
            //system("PAUSE");
    
            deal_list = new data2[listSize];
            
            deal_list[1].num = list[0].num;
            deal_list[1].student = list[0].student;
            deal_list[1].floor = 2;
            deal_list[1].type = "min";
            deal_list[2].num = list[1].num;
            deal_list[2].student = list[1].student;
            deal_list[2].floor = 2 ;
            deal_list[2].type = "max";
            
        	if (deal_list[1].student > deal_list[2].student ) Swap(1,2) ;
        	
        	
            for(int i = 3 ; i <= listSize ; i++ ){ 
            	deal_list[i].num = list[i-1].num ;
                deal_list[i].student = list[i-1].student ;
                int floortemp = 1 ;
                for( int z = i ; z > 0 ; z = (z-1)/2) floortemp++ ;
                deal_list[i].floor = floortemp ;
            
        
                int opposite = 0; // max�������I 
                int oppositeDAD = 0 ; // min�������I������ 
                int parent_num = (i-1)/2;
                
                if ( deal_list[parent_num].type == "min" ){
                	if(i != listSize) deal_list[i].type = "min";
                	oppositeDAD = ( (i+pow(2,deal_list[i].floor-2)) - 1 ) / 2;
        	        if (deal_list[i].student > deal_list[oppositeDAD].student ) {
        	            Swap(i,oppositeDAD) ;
        	            for(int num = oppositeDAD ; num > 2 ; num = (num-1)/2){
        	                if ( deal_list[num].student > deal_list[(num-1)/2].student )Swap(num,(num-1)/2) ;
				            else break;	
			            } //maxheap ;
					} // �P�̤j��n�������I�����`�I������A�p�G�j��L�N�n���L�h 
					
					for(int num = i; num > 1 ; num = (num-1)/2){
        	            if ( deal_list[num].student < deal_list[(num-1)/2].student ) Swap(num,(num-1)/2) ;
				        else break;	
			        } // minheap
				    
				}
                else if ( deal_list[parent_num].type == "max" ){
                	if(i != listSize) deal_list[i].type = "max";
                    opposite = i - pow(2,deal_list[i].floor-2) ;
        	        if (deal_list[i].student < deal_list[opposite].student ) {
        	            Swap(i,opposite) ;	
        	        	for(int num = opposite; num > 1 ; num = (num-1)/2){
        	                if ( deal_list[num].student < deal_list[(num-1)/2].student ) Swap(num,(num-1)/2) ;
				            else break;	
			            } // minheap
					}  // �P�̤p��n�������I������A�p�G�p��L�N�n���L�h  
					for(int num = i ; num > 2 ; num = (num-1)/2){
        	            if ( deal_list[num].student > deal_list[(num-1)/2].student )Swap(num,(num-1)/2) ;
				        else break;	
			        } // maxheap
				}
				
				//for(int a = 1; a < i; a++) cout << deal_list[a].student << "\n";
				//system("pause");
				
            }

            
            cout<< "<DEAP>\n"<< "bottom: [" << deal_list[listSize].num << "] " << deal_list[listSize].student << endl ;
            int mostleft;
            for(int i = 1;i <= listSize;i = i*2+1) mostleft = i;
            cout << "leftmost bottom: [" << deal_list[mostleft].num << "] " << deal_list[mostleft].student << endl;
            
            
            deal_list = new data2[listLength];
            list = new data[listLength];
            listSize = 0;
			A.close();

            //system("PAUSE");
            

        }
        
        
        void mission3() {

	        string file_number;
  	    	cout << endl << "Input a file number (e.g., 101, 102, 103, ...): ";
  		    cin >> file_number;
  			file_number = "input" + file_number + ".txt";
    		fstream A;
    		A.open( file_number.c_str(), ios::in );
	        
	        if( A.is_open() == true ) {
        		string temp ;
	        	getline(A,temp); // �����e3 
				getline(A,temp);
				getline(A,temp);
				
        	    while( A.eof() == false ) {
                    if(listSize == listLength) expansion_ListLength(); 
                    getline( A,temp );
        			if (temp != "\0"){
        			  list[listSize].num = listSize+1 ;
        			  int tap = 1 ;
                      for(int x = 1 ; x <= temp.length() - 1 ; x++ ){
            	        if ( temp[x] == '\t' ) tap++ ;
            	        if ( tap == 7) {
            	        	if (is_number(temp[x])) {
            	        		list[listSize].student = list[listSize].student*10 + (temp[x] - '0' ) ;
            	        		//cout << list[listSize].student << endl;
							}
						}  // �Ntxt�ɪ��ǥͼƤ��X�ӡA�é��ʺA�}�C 
				        
			          }
			          //cout << list[listSize].student << endl;
			          //system("pause");
			          listSize++;
			        }
			        
                    
                }// while
	            
        	} // if( first.is_open() == true )
            else {
                cout << endl << "### " << file_number << " does not exist! ###\n";
                return mission3();
            } 
            
            //system("PAUSE");
    
            deal_list = new data2[listSize];
            
            deal_list[0].num = list[0].num;
            deal_list[0].student = list[0].student;
            deal_list[0].type = "min";
            int num = 0;
            int parent_num = 0;
            int pp = 0;
            //deal_list[2].num = list[1].num;
            //deal_list[2].student = list[1].student;
            //deal_list[2].floor = 2 ;
            //deal_list[2].type = "max";
            
        	//if (deal_list[1].student > deal_list[2].student ) Swap(1,2) ;
        	// �p�G�ƥ�min�N�n���̤p 
			//         max    ��Ƨ@�̤j �t�t�̤p 
        	
            for(int i = 1 ; i < listSize ; i++ ){ 
            	deal_list[i].num = list[i].num ;
                deal_list[i].student = list[i].student ;
                //int floortemp = 1 ;
                //for( int z = i ; z > 0 ; z = (z-1)/2) floortemp++ ;
                //deal_list[i].floor = floortemp ;
                
                num = i;
                parent_num = (num-1)/2;
                
                
                if ( deal_list[parent_num].type == "min" ){
                	if(i != listSize) deal_list[i].type = "max";
                	//oppositeDAD = ( (i+pow(2,deal_list[i].floor-2)) - 1 ) / 2;
                	
                	num = i;
                	parent_num = (num-1)/2;
                	//pp = (parent_num-1)/2;
                	if ( deal_list[num].student < deal_list[parent_num].student ) {
                		Swap(num, parent_num);
                		num = parent_num;
                		parent_num = (num-1)/2;
                		pp = (parent_num-1)/2;
                		while ( num != 0 ){
        	                if ( deal_list[num].student < deal_list[pp].student ) Swap(num, pp) ;
        	                num = pp;
        	                parent_num = (num-1)/2;
        	                pp = (parent_num-1)/2;
			            }//minheap
                		
                		
					}
					
					num = i;
					parent_num = (num-1)/2;
					pp = (parent_num-1)/2;
				    while ( parent_num != 0 ){
        	            if ( deal_list[num].student > deal_list[pp].student ) Swap(num, pp) ;
        	            num = pp;
        	            parent_num = (num-1)/2;
        	            pp = (parent_num-1)/2;
			        } // maxheap                	
                	
				} // �L�������O�Omin 
                else if ( deal_list[parent_num].type == "max" ){
                	if(i != listSize) deal_list[i].type = "min";
                    //opposite = i - pow(2,deal_list[i].floor-2) ;
                    num = i;
                	parent_num = (num-1)/2;
                	//pp = (parent_num-1)/2;
                    
                    if ( deal_list[num].student > deal_list[parent_num].student ) {
                    	Swap(num, parent_num); 
                    	num = parent_num;
                    	parent_num = (num-1)/2;
                    	pp = (parent_num-1)/2;
				        while ( parent_num != 0 ){
        	                if ( deal_list[num].student > deal_list[pp].student ) Swap(num, pp) ;
        	                num = pp;
        	                parent_num = (num-1)/2;
        	                pp = (parent_num-1)/2;
			            } // maxheap  
					}
					
				    num = i;
                	parent_num = (num-1)/2; 
                	pp = (parent_num-1)/2;
                	while ( num != 0 ){
        	            if ( deal_list[num].student < deal_list[pp].student ) Swap(num, pp) ;
        	            num = pp;
        	            parent_num = (num-1)/2;
        	            pp = (parent_num-1)/2;
			        }//minheap
					  
				} // �L�������O�Omax 
				
				//for(int a = ; a < i; a++) cout << deal_list[a].student << "\n";
				//system("pause");
				
            }
            
            
            cout<< "<min-max heap>"<< endl ;
            cout << "root: [" << deal_list[0].num << "] " << deal_list[0].student << endl ;
            cout << "bottom: [" << deal_list[listSize-1].num << "] " << deal_list[listSize-1].student << endl ;
            int mostleft;
            for(int i = 1;i <= listSize;i = i*2+1) mostleft = i;
            cout << "leftmost bottom: [" << deal_list[mostleft].num << "] " << deal_list[mostleft].student << endl;
            
            
            deal_list = new data2[listLength];
            list = new data[listLength];
            listSize = 0;
			A.close();

            //system("PAUSE");
            

        } // mission3 
        
        void Swap(int a,int b){
            data2 *templist = new data2;
            templist->num= deal_list[a].num;
            templist->student = deal_list[a].student;
            deal_list[a].num = deal_list[b].num;
            deal_list[a].student = deal_list[b].student;
            deal_list[b].num = templist->num;
            deal_list[b].student = templist->student;
        }
        
        
        void expansion_ListLength(){
            data *cList = list ;
	        list = new data[listLength*100];	
	        for( int k = 0 ; k < listLength ; k++ ) list[k] = cList[k];
	        delete [] cList;
	        listLength = listLength * 100; 
	    } // expansion_ListLength()

		bool is_number(char num){
			if(num == '0') return true;
			else if(num == '1') return true;
			else if(num == '2') return true;
			else if(num == '3') return true;
			else if(num == '4') return true;
			else if(num == '5') return true;
			else if(num == '6') return true;
			else if(num == '7') return true;
			else if(num == '8') return true;
			else if(num == '9') return true;
			else return false;
		}
    void getcommand(){  
       int choice;
        cout << "\n" ;
        printf("*  Heap Construction  *\n");
        printf("* 0. Quit             *\n");
        printf("* 1. Build a max heap *\n");
        printf("* 2. Build a DEAP     *\n");
        printf("***********************\n");
        printf("Input a choice(0, 1, 2, 3): ");
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
 
  return 0;
}
