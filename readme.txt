    BCNRANDOM, last change 27/4/2014

	This is the C language version of the library bcnrandom, which  generates
	uniform random variates of type double on (0,1), using the linear
	Congruential Generator (LCG) by J. Borwein and D. Bailey. 

	There are two generators, the basic and the combined. The basic generator is of
	a good quality and has the period of approx 10^15. Its advantage is that it is
	very fast, twice as fast if compared to the very basic (and poor quality) standard 
	C function rand(). The combined generator is a bit slower (still faster than rand()), 
	but it has the period of 10^23, and it passes all the tests in BigCrush suite
	of tests. The random numbers are not of cryptographic strength, but are well
	suited for numerical simulations, especially in parallel processes, where
	the sam sequence of random variate is obtained when using any number of threads.
	This is because of the valuable skip ahead feature. The seed is the starting position
	in the sequence of random variates.

	The implementation is in the .h file, which means that only include statement is needed
	to start using this generator.
 

 	The random variates in the basic generator are generated by iterating
	                       z_{k+1} = 2^53 z_k mod 3^33. 
	The actual random variate is computed by 
	                            x = z_{k+1} * 3^-33. 
	The period is approx 10^15. Random variates can be generated in parallel 
	and in multiple threads, although this version of the code is not always
	guaranteed to be thread safe, see notes below.

	A combined LCG is also used to ensure even better statistical quality
	of the generated sequence. The combined generator is marginally slower than
	J. Borwein and D. Bailey's LCG, but gives a longer period and passes
	Birthday spacings and Closed pairs tests as well.

	The pseudorandom sequence passes statistical tests of BigCrunch test of
	TestU01 suite. The description of the method is published in

	Beliakov, G., Creighton, D., Johnstone, M. and Wilkin, T. 2013, Efficient implementation 
	of Bailey and Borwein pseudo-random number generator based on normal numbers, 
	Computer physics communications, vol. 184, no. 8, pp. 1999-2004.

	G. Beliakov, M. Johnstone, D. Creighton, T. Wilkin, 2012, An efficient implementation of 
	Bailey and Borwein's algorithm for parallel random number generation on graphics processing
	units, Computing 94(5): 433-447.

	G. Beliakov, M. Johnstone, D. Creighton, T. Wilkin, Parallel random
	variates generator for GPUs based on normal numbers, ArXiv 1206.1187
	http://arxiv.org/abs/1206.1187,

	see also	
	http://www.deakin.edu.au/~gleb/bcn_random.html

	
	Usage: Follow the examples presented here.

		The user desires to generate a sequence of pseudorandom variates starting from 
		a chosen position (seed).  The value of seed should be in the range of
		            [0,3448138688185369]  =  [0,2^53-3^33-100]

     Step 1 Initialize the generator with "seed" 
			
		 	seedbcn(seed);


     Step 2 is to generate random variates. It is accomplished by calling  this code:
			
    		for (int i = 0 ; i < N ; i++)
   			{
				generated_value =  randbcn();
			...// using generated_value
        		}
			

			
	Example program :
		See file testbcnrand.c

	More detailed comments are at the start of bcnrandom.h file

	All essential code is in bcnrandomc.h file. The file testbcnrand.c is a test/
	illustration program. Compile the test program using make. Then
	execute using ./bin/testrand 
	

	This program is freeware. 

	Please cite our work
	Beliakov, G., Creighton, D., Johnstone, M. and Wilkin, T. 2013, Efficient implementation 
	of Bailey and Borwein pseudo-random number generator based on normal numbers, 
	Computer physics communications, vol. 184, no. 8, pp. 1999-2004.

	G. Beliakov, M. Johnstone, D. Creighton, T. Wilkin, 2012, An efficient implementation of 
	Bailey and Borwein's algorithm for parallel random number generation on graphics processing
	units, Computing 94(5): 433-447.
	see also	http://arxiv.org/abs/1206.1187, http://www.deakin.edu.au/~gleb/bcn_random.html

	Copyright Gleb Beliakov, Tim Wilkin and Michael Johnstone, 2013




