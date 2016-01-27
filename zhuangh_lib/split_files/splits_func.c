
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <malloc.h>
#include <iostream>
#include <vector>

using namespace std;

//int main(int argc, char *argv[])
int splits_func( const string filename, vector<int> chunk_size)
// int splits_func( const string filename, int  filesize  )
{

    char splitfn[280];
    long part = 0;
    int chunk = 100 * 1024;

    FILE *fp, *op;
    //char *fb;
    void *fb;
    string ofn = "StdIn";
    
 
    long lch = 5;// filesize;

    if (lch < 1) {
	fprintf(stderr, "Invalid chunk size.\n");
	return 2;
    }
    chunk = lch  * 1024L;

    fb = malloc((unsigned) chunk);
    if (fb == NULL) {
	fprintf(stderr, "Unable to allocate %d byte I/O buffer.\n", chunk);
	return 1;
    }
    ofn = filename;
    fp = fopen(filename.c_str(), "rb");
    fseek(fp,0L,SEEK_END);
    int sz = ftell(fp);
    fseek(fp,0L,SEEK_SET);
    // cout<< sz<<endl;
    int sum  = 0;
    for ( std::vector<int>::iterator it = chunk_size.begin(); it!= chunk_size.end(); it++){
//	cout<<*it<<endl;	
	sum += *it;
    }
  //  cout<<sum<<endl;

    std::vector<int> f_offset;
    // init the first element 
    //    f_offset.push_back(0);
    //   std::vector<int>::iterator off =  f_offset.begin(); 
    int tmp = 0;
    for (std::vector<int>::iterator it = chunk_size.begin(); it!= chunk_size.end(); it++){

	*it = (int) ((( double ) (*it)) /sum*sz);
	tmp = tmp+(*it);
	if( it == chunk_size.end()-1 ){
	    tmp = tmp -(*it);
	    *it = sz - f_offset.back(); 
	    tmp = tmp+(*it);
//	    cout<<tmp<<"!!!!"<<endl;
	}

//	cout<<*it<<" :" ;	
//	cout<<tmp<<endl;
	f_offset.push_back(tmp);

//	int fsize = *(off-1)+ ( *it);
//	cout<<*(off-1)<<":"<<(*it)<<endl;
//	f_offset.push_back(fsize);   
//	off++;
    }
 //   std::vector<int>::iterator ite = chunk_size.end()-1;
//    chunk_size.push_back( sz - (*ite) ); 

 //   cout<<endl<<endl;

    for (std::vector<int>::iterator it = chunk_size.begin(); it!= chunk_size.end(); it++){
//	cout<<*it<<endl;	
//	cout<<*it<<endl;
    }
    // cout<<endl<<endl;
    for (std::vector<int>::iterator it = f_offset.begin(); it!= f_offset.end(); it++){
//	cout<<*it<<endl;	
	// cout<<*it<<endl;
    }
 



    // cout<<sum<<endl;



   if (fp == NULL) {
	fprintf(stderr, "Cannot open file %s\n", filename.c_str());
	return 2;
    }



   int i = 0;
    while (1) {
	long fl;
//	chunk = chunk_series[part];


//	fl = fread(fb, 1, (int) chunk, fp);
	fl = fread(fb, 1, (int) chunk_size[i++],fp);
	if (fl > 0) {
	    sprintf(splitfn, "%s.%03ld", ofn.c_str(), ++part);
	    op = fopen(splitfn, "wb");
	    if (op == NULL) {
                fprintf(stderr, "Cannot create output file %s\n", splitfn);
		return 2;
	    }
	    fwrite(fb, 1, (int) fl, op);
	    fclose(op);
	    // sha send
	} else {
	    break;
	}

    }
    if (fp != stdin) {
	fclose(fp);
    }


   

    printf("It is divided into %ld part\n",part);

    return 0;
}


int main(){
    // 12,42,54,13,46,87,32,43,90,132,64,74,
    // 56,82,92,16,156,137,127,148,48,23,74,
    // 96,46,18,187,85,167,201,80,158

    vector<int> chunk_size;
    //jchunk_size.resize(32);
//    for ( std::vector<int>::iterator it = chunk_size.begin(); it!= chunk_size.end(); it++){
    for(int i = 1 ; i<=32;i++){
	chunk_size.push_back( rand()%255);
	// cout<<chunk_size[i-1]<<endl;	
    }
    // cout<<"before input "<<endl;
    splits_func("div_test.exe", chunk_size );
    return 0;
}
