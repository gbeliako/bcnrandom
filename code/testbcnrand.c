#include <stdio.h>
#include "bcnrandomc.h"

/*
	Test program for pseudo-random number generator
	based on Borwein and Bailey's linear congruential
	generator	 
*/

int main( void )
{
	/* Seed value for generator */
	uint64_t	seed = 1;
	uint64_t	lcgseed = 1;
	
	/* Iterate variables */
	uint32_t	i = 0,
				count = 0,
				MAX_ITS = 1000000;
	/* Variables for measuring statistics of test */
	double r = 0,
		   rsum = 0,
		   ravg = 0,
		   rprop = 0;

	/* Seed the generator */
	/* seedbcn(seed);
	   seedlcg(lcgseed); */
	seedCombined(seed);

	/*r = randbcn();*/
	r = randCombined();
	
	/* 
		Generate MAX_ITS pseudo-random numbers, compute
		average of set of numbers and proportion less
		than or equal to 0.9
	*/
	
	
	for (i = 0; i < MAX_ITS; i++)
	{
	/* we can use either BCN or combined generator */
		/*r = randbcn();*/
		r = randCombined();
		rsum += r;
		if (r <= 0.9)
			count++;
	}
	ravg = rsum / (float)MAX_ITS;
	rprop = count / (float)MAX_ITS;

	/* Display statistics */
	printf("The mean of the generated numbers is %10.9f (expected 0.5)\n",ravg);
	printf("The proportion of numbers less than 0.9 is %10.9f (expected 0.9)\n",rprop);

/* Example using thread safe versions */

	seedCombinedTS(seed, &seed, &lcgseed);

/* BCN generator */
	r = randbcnTS(&seed);

/* combined generator */
	r = randCombinedTS(&seed, &lcgseed);

/*  skip ahead property: the seed is chosen as to start with the M-th element of the sequence (here M=20000) */

	count = 20000;
	seed=0;
	lcgseed=0;
/* seed both generators */
	seed=seedbcn(seed*53);
	lcgseed=seedlcg(lcgseed);
	for (i = 0; i < count; i++)
	{
	/* we can use either BCN or combined generator */
		r = randCombinedTS(&seed, &lcgseed);
	}

	r = randCombinedTS(&seed, &lcgseed );
	printf("iterating %d steps the generated value is %f \n",count,r);
	
/* skip ahead, alterntive simpler seeding function */
	seedCombinedTS(count, &seed, &lcgseed);

	r = randCombinedTS(&seed, &lcgseed );
	printf("skipping  %d steps the generated value is %f \n",count,r);


	return 0;
}