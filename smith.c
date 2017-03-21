#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COMPUTATIONS 100000										/* This is a program that finds all the Smith numbers among 100.000 random numbers and displays the percentage */

int main(void)
{
	long i, tempnum, factor, number, sum_factors, temp_for_sumdigs, digs_sum, curtime, prime_sum, prime_sum2, tempnum2;	/* Tempnum stands for the temporary value of the number. Number represents the numbers produced by the rand function.*/
	double percentage;	/* Curtime declares the current time of the computer and is used as a seed for the srand function. Factor represents the number's prime factors. Sum_factors stands for the sum of the factors.  */
	int count = 0;		/*  Temp_for_sumdigs stands for the number's digits sum. Digs_sum is the variable used to depict the number's sum of its digits. Prime_sum is the sum of the prime factors.  */
	curtime = time (NULL);	/* Prime_sum2 is the sum of the prime factors whose square is greater than the tempnum. Tempnum2 receives its value from the number produced by the rand function. Count counts the Smith numbers and percentage displays the percentage of the Smith numbers. */
	srand((unsigned int) curtime);			
	for (i = 1; i <= COMPUTATIONS ; i++) {			
		sum_factors = 0;
		number = ((rand()%32768)+1)*((rand()%32768)+1)+1;
		tempnum = number;
		while (tempnum % 2 == 0) {
			temp_for_sumdigs = 2;	
			while (temp_for_sumdigs != 0){												/* Finds the number's "2" factors */
				sum_factors = sum_factors + temp_for_sumdigs % 10;
				temp_for_sumdigs = temp_for_sumdigs / 10;
			}
			tempnum = tempnum / 2;
		}
		factor = 3;
		while (factor*factor <= tempnum){												/* Finds the number's prime factors starting from 3 */
			while (tempnum % factor == 0){
				prime_sum = factor;
				while (prime_sum != 0){
					sum_factors = sum_factors + prime_sum % 10;
					prime_sum = prime_sum / 10;
				}
					tempnum = tempnum / factor;
			}
			factor = factor + 2;	
		}
		if((tempnum != 1) && (sum_factors != 0)){																/* If tempnum > factor*factor then at this point the program finds the remaining prime factors that have usually high values */
			prime_sum2 = tempnum;
			while (prime_sum2 != 0){
				sum_factors = sum_factors + prime_sum2 % 10;
				prime_sum2 = prime_sum2 / 10;
			}
		}
		tempnum2 = number;	
		digs_sum = 0;	
		while (tempnum2 != 0){															/* Finds the number's digits sum */
			digs_sum = digs_sum + tempnum2 % 10;
			tempnum2 = tempnum2 / 10;	
		}
		if(sum_factors == digs_sum){														/* Checks if the number is a Smith number */
			count = count + 1;
			printf(" %ld is a Smith number, sum is %ld \n", number, sum_factors);
		}
	}
	percentage = ((double)count * 100) / COMPUTATIONS;
	printf("\nFound %lf %% Smith numbers\n", percentage);
	printf("\nCurrent time is: %ld\n", curtime);
}
