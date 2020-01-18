#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <sys/time.h>


double my_power(double x, int n)
{
  // PUT YOUR CODE HERE
}



double my_recursive_power(double x, int n)
{
  // PUT YOUR CODE HERE
}






// begin TIMING variables
int signal ;
struct timeval Tp;
struct timezone Tzp ;
long sec,usec ;
double dsec1, dsec2 ;
// end TIMING variables


void begin_timing()
{
  signal = gettimeofday(&Tp,&Tzp) ;
  usec = Tp.tv_usec ;
  sec = Tp.tv_sec ;
  dsec1 = sec + usec/1000000.0 ;
}


  
void end_timing()
{
  signal = gettimeofday(&Tp,&Tzp) ;
  usec = Tp.tv_usec ;
  sec = Tp.tv_sec ;
  dsec2 = sec + usec/1000000.0 ;
}






int test01(int n)
{
  int numreps,i ;

  printf("\n===================================================\n") ;
  printf("Exponent = %d\n",n) ;
  numreps = 10000000 ; // ten million
  printf("numreps = %d\n",numreps) ;
  printf("\n") ;
  
  //======================================================================
  printf("obvious power algorithm : \n") ;
  //======================================================================

  double x,p ;
  
  begin_timing() ;
  srandom(100) ;
  for (i = 0 ; i < numreps ; i++) {
    x = 2*drand48() ;
    p = my_power(x,n) ;
    //  printf("%e\n",p) ;
  }
  end_timing() ;
  printf("Total time of %d reps is %18lf seconds\n",numreps, dsec2 - dsec1) ;
  printf("Average time took %e seconds.\n", (dsec2 - dsec1)/numreps) ;


  
  //======================================================================
  printf("recursive power algorithm : \n") ;
  //======================================================================

  
  begin_timing() ;
  srandom(100) ;
  for (i = 0 ; i < numreps ; i++) {
    x = 2*drand48() ;
    p = my_recursive_power(x,n) ;
    //  printf("%e\n",p) ;
  }
  end_timing() ;
  printf("Total time of %d reps is %18lf seconds\n",numreps, dsec2 - dsec1) ;
  printf("Average time took %e seconds.\n", (dsec2 - dsec1)/numreps) ;  
  

  
}



int main()
{
  printf("%lf %lf %lf\n",pow(2.5,14), my_power(2.5, 14), my_recursive_power(2.5,14)) ;

  test01(100) ;
  test01(1000) ;      
}
