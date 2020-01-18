#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <sys/time.h>

int num_count = 0;

double my_power(double x, int n)
{
  // PUT YOUR CODE HERE
		  
  double ans = 1;
  for(int i = 0; i < n; i++)
  {
		  ans = ans * x;
		  ++num_count;
  }
  return ans;
		  
}



double my_recursive_power(double x, int n)
{
  // PUT YOUR CODE HERE
  if (n == 0)
		  return 1;
  else if (n%2 == 0)
  {
		  ++num_count;
		  return my_recursive_power(x * x, n / 2);
  }
  else
  {
		  num_count += 2;
		  return my_recursive_power(x * x, (n - 1) / 2) * x;
  }
		  
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
	num_count = 0;
    x = 2*drand48() ;
    p = my_power(x,n) ;
    //  printf("%e\n",p) ;
  }
  end_timing() ;
  printf("Total time of %d reps is %18lf seconds\n",numreps, dsec2 - dsec1) ;
  printf("Average time took %e seconds.\n", (dsec2 - dsec1)/numreps) ;
  printf("Number of multiplies: %d \n", num_count);


  
  //======================================================================
  printf("recursive power algorithm : \n") ;
  //======================================================================

  
  begin_timing() ;
  srandom(100) ;
  for (i = 0 ; i < numreps ; i++) {
	num_count = 0;
    x = 2*drand48() ;
    p = my_recursive_power(x,n) ;
    //  printf("%e\n",p) ;
  }
  end_timing() ;
  printf("Total time of %d reps is %18lf seconds\n",numreps, dsec2 - dsec1) ;
  printf("Average time took %e seconds.\n", (dsec2 - dsec1)/numreps) ;  
  printf("Number of multiplies: %d \n", num_count);
  

  
}



int main()
{
  printf("%lf %lf %lf\n",pow(2.5,14), my_power(2.5, 14), my_recursive_power(2.5,14)) ;

  test01(100) ;
  test01(1000) ;      
}
