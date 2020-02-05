#include <stdio.h>     
 #include <unistd.h>   
 
test()   
 {   
      char buf[80];   
      getcwd(buf,sizeof(buf));   
      printf("current working directory: %s\n", buf);   
 }  
 main(){
	test();
 }