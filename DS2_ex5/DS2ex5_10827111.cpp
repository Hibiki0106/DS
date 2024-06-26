//10827111  
#include <string> 
#include <iostream> 
#include <fstream> 
#include <cstdlib> 
#include <iomanip> 
#include <cstring> 

#include <vector>
#include <cstdio>
#include <ctime>
#include <sstream>
#include <math.h>
#include <stack> 

using namespace std;

struct Data {
	char putID[10];
	char getID[10];
	float weight;
};

struct DataP{
	float weight;
	int address;
};

string int2str(int i) {
  	string s;
  	stringstream ss(s);
  	ss << i;

  	return ss.str();
}

char* Str2char(string s){							
	char* str = new char[s.length() + 1]; 
	for(int a = 0; a < s.length(); a++) str[a] = s[a];
	str[s.length()] = '\0' ;
	return str;
} // Str2char()

class ExternalSort { 
	public : int numOflist;			// 總共有幾個檔案 (暫時分割檔 
	public : int timesOfDivide;		// 第幾次的分割 
	
	/*
	製造數個分割檔 
	*/
	public: void createlist( string Num ){				
		string finName ; 			// 輸入檔名 
		string foutName ;			// 輸出檔名 
		fstream fin ;				// 輸入檔 
		fstream fout ;				// 輸出檔 
		vector<Data> outlist ;		// 存200筆資料陣列 
		Data temp ;					// 暫存輸入 
		
		numOflist = 0 ;
		timesOfDivide = 0 ;
		finName = "pairs" + Num + ".bin";
		fin.open( finName.c_str(), fstream::in | fstream::binary ) ;
		while ( fin ) {
			outlist.push_back( temp );
			fin.read((char*)&temp, sizeof(temp)) ;
			if( outlist.size() == 200 ) { // 參數固定在200 
				WeightSort(outlist);
				foutName = "sorted" + Num + "_" + int2str(timesOfDivide + 1) + "_" + int2str(numOflist + 1) + ".bin";
				fout.open(foutName.c_str(), fstream::out | fstream::binary );
      			for ( int a = 0 ; a < outlist.size() ; a++ ){
      				fout.write((char*)&outlist[a], sizeof(outlist[a]));
				} // for
      
      			fout.close();
				outlist.clear();
				numOflist++;
			} // if 
		} // while
		if( outlist.size() != 0 ) {
			WeightSort(outlist);
			foutName = "sorted" + Num + "_" + int2str(timesOfDivide + 1) + "_" + int2str(numOflist + 1) + ".bin";
			fout.open(foutName.c_str(), fstream::out | fstream::binary );
      		for ( int a = 0 ; a < outlist.size() ; a++ ){
      			fout.write((char*)&outlist[a], sizeof(outlist[a]));
			} // for
			
			fout.close();
			outlist.clear();
			numOflist++;
		} // if
	
		timesOfDivide++ ; 
		fin.close() ;
		
	} // create a list()
	
	public: void merge( string Num ){
		string finName1, finName2 ; 				// 輸入檔名
		string outputFileName ;						// 輸出檔名 
		fstream fin1, fin2 ;						// 輸入檔 
		fstream fout ;								// 輸出檔 
		int numOfRun = ( numOflist + 1 ) / 2 ; 		// 要合併幾次 
		Data temp1, temp2 ;							// 暫存輸入
		
    	for ( int a = 1 ; a <= numOfRun ; a++ ) { 
      		int divideNum1 = a * 2 - 1 ; 			// 分割檔編號1 
      		int divideNum2 = a * 2 ; 				// 分割檔編號2
			   
      		outputFileName = "sorted" + Num + "_" + int2str(timesOfDivide + 1) + "_" + int2str(a) + ".bin";
      		fout.open(outputFileName.c_str(), fstream::out | fstream::binary );
        
      		if ( divideNum2 <= numOflist ) { 	// 無輸入檔案 或 剩下單一檔案 
        		finName1 = "sorted" + Num + "_" + int2str(timesOfDivide)+ "_" + int2str(divideNum1) + ".bin";
        		finName2 = "sorted" + Num + "_" + int2str(timesOfDivide)+ "_" + int2str(divideNum2) + ".bin";
        
        		fin1.open(finName1.c_str(), ios::in | ios::binary);
        		fin1.read((char*)&temp1, sizeof(temp1));
        		fin2.open(finName2.c_str(), ios::in | ios::binary);
        		fin2.read((char*)&temp2, sizeof(temp2));
				
				// merge start
        		while ( fin1 && fin2 ) {	// 其中一個檔案讀空		
          			if ( temp1.weight >= temp2.weight ) {  
            			fout.write((char*)&temp1, sizeof(temp1));
            			fin1.read((char*)&temp1, sizeof(temp1));
          			} // if()
          			else {
            			fout.write((char*)&temp2, sizeof(temp2));
           				fin2.read((char*)&temp2, sizeof(temp2));
         			} // else
        		} // while()
				
				// 將另一個尚未讀空的檔案讀空
			
				while ( fin1 ) {
          			fout.write((char*)&temp1, sizeof(temp1));
         			fin1.read((char*)&temp1, sizeof(temp1));
        		} // while()
			
        		while ( fin2 ) {
          			fout.write((char*)&temp2, sizeof(temp2));
          			fin2.read((char*)&temp2, sizeof(temp2));
        		} // while()
			
				
        		fin1.close();
        		fin2.close();
        		fout.close();
        		remove(finName1.c_str());
        		remove(finName2.c_str());
        		
      		} // if()
      		else {	// 剩單一檔案 
        		finName1 = "sorted" + Num + "_" + int2str(timesOfDivide)+ "_" + int2str(divideNum1) + ".bin";

        		fin1.open(finName1.c_str(), ios::in | ios::binary);
        		fin1.read((char*)&temp1, sizeof(temp1));

        		while ( fin1 ) {
          		fout.write((char*)&temp1, sizeof(temp1));
          		fin1.read((char*)&temp1, sizeof(temp1));
        		} // while()

        		fin1.close();
        		fout.close();
        		remove(finName1.c_str());
      		} // else
    	} // for
    	
    	timesOfDivide++;
    	numOflist = numOfRun;
    	cout << endl << "Now there are " << numOflist << " runs." << endl;
    	if( numOflist == 1 ){ // 總合併完成 
    		writefile(Num);
		} // if
		else{
			merge(Num);
		} // else
	} // merge()
	
	private : void writefile( string Num ){
		string finName ;
		string foutName ;
		fstream fin ;
		fstream fout ;	
		Data temp ;
								
		finName = "sorted" + Num + "_" + int2str(timesOfDivide)+ "_1.bin";
		fin.open(finName.c_str(), fstream::in | fstream::binary );
	
    	fin.read((char*)&temp, sizeof(temp));
		
		foutName = "sorted" + Num + ".bin";
		fout.open(foutName.c_str(), fstream::out | fstream::binary );
		
		
		while ( fin ) {
			if( temp.weight == 0) break;
			fout.write((char*)&temp, sizeof(temp));
			fin.read((char*)&temp, sizeof(temp));
		} // while
		
		fin.close();
		fout.close();
		remove(finName.c_str());
	} // writefile()
	
	/*
	依照權重由大而小進行排序 
	*/
	private: void WeightSort(vector<Data> &outlist){
		for ( int i = outlist.size() - 1 ; i > 0 ; i-- ) {
			for ( int j = 0 ; j < i ; j++ ) {
				if ( outlist[j].weight < outlist[j+1].weight ) {
					swap( outlist[j], outlist[j+1] ) ;
				} // if 
			} // for
		} // for
	} // sortWeight()
	
	public : void primaryIndex( string Num ){
		fstream fin ;				// 輸入檔 
		string finName ;			// 輸入檔名 
		Data temp ;					// 暫存輸入
		vector<DataP> plist ;		// 主索引
		DataP ptemp;				// 暫存索引
		float weightnow ;  			// 目前權重 
		
		finName = "sorted" + Num + ".bin";
		fin.open(finName.c_str(), fstream::in | fstream::binary );
		
		fin.read((char*)&temp, sizeof(temp));
		ptemp.weight = temp.weight;
		ptemp.address = 0;
		weightnow = ptemp.weight;
		plist.push_back(ptemp);
		for ( int a = 1 ; fin ; a++ ) {
			fin.read((char*)&temp, sizeof(temp));
			if( temp.weight != weightnow  ){
				ptemp.weight = temp.weight;
				ptemp.address = a;
				weightnow = ptemp.weight;
				plist.push_back(ptemp);
			} // if
		} // for
		
		cout << endl << endl << "<Primary index>: (key, offset)" << endl;
		for( int a = 0 ; a < plist.size() ; a++ ){
			cout << "[" << a+1 << "] (";
			cout << plist[a].weight << ", " << plist[a].address << ")" << endl;
		} // for
	} // primaryIndex()
	
}; // ExternalSort 


int main(){
  int command;
  bool done1 = false;
  ExternalSort ex;
  string Num;
  double internalSortTime = 0;
  double externalSortTime = 0;
  
  do {
  	cout << endl << "***********************************************" ;
	cout << endl << "On-machine Exercise 05                        *" ;
	cout << endl << "Mission 1: External Merge Sort on a Big File  *" ;
	cout << endl << "Mission 2: Construction of Primary Index      *" ;
	cout << endl << "***********************************************" << endl ;
	cout << endl << "########################################################" ;
	cout << endl << "Mission 1: External merge sort" ;
    cout << endl << "########################################################" ;

    fstream fin ;
    cout << "\n\nInput a file number (e.g., 501, 502, 503, ...[0] Quit): ";
    cin >> Num;
    string fileName;
    fileName = "pairs" + Num + ".bin";
    fin.open( fileName.c_str(), fstream::in | fstream::binary ) ;
    while ( !fin.is_open() ) {
        if (Num == "0") break;
        cout << endl << "### file does not exist! ###" << endl;
        cout << endl << "Input a file number (e.g., 501, 502, 503, ...[0] Quit): ";
        cin >> Num;
        fileName = "pairs" + Num + ".bin";
      	fin.open( fileName.c_str(), fstream::in | fstream::binary ) ;
    } // while
	fin.close();
	if (Num == "0") break;
	
	internalSortTime = clock();
	ex.createlist( Num );
	internalSortTime = clock() - internalSortTime;
	externalSortTime = clock();
	ex.merge( Num );
	externalSortTime = clock() - externalSortTime;
	cout << endl << "The execution time ...";
	cout << endl << "Total Execution Time = " << internalSortTime + externalSortTime << "ms\n";
	
	
	system("pause");
	cout << endl << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout << endl << "Mission 2: Build the primary index";
	cout << endl << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	
	ex.primaryIndex( Num );
	
  } while (1);
  
  cout << endl << "Bye Bye!" << endl;
} // main()
