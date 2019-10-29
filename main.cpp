//huyhuyhuy
#include <iostream>
#include <time.h>
#include <vector>
#include <iomanip>
#define number 100


unsigned int spry_coin_flip()
{
	return rand() & 1;
	//return time(0) && 1;
}
unsigned int custom_spry_random(unsigned int N)
{
	//fill in code here (use spry_coin_flip(�) from step one)
	//do not call a random number generator directly
	// return num = 1 .... N
	//unsigned int result = 0;
	//for (int i = 0; i < N; i++)
	//{
	//	int a = spry_coin_flip();
	//	result = ((result << 1)|a);
	//}
	//return (result%N)+1;

	//for (int i = 0; i < 100; i++)
	//{
	//	result += spry_coin_flip();
	//}
	//return result%N+1;


	unsigned int result = 0;
	for (int i = 0; i < N*N; i++)
	{
		//result+=spry_coin_flip();
		int a = spry_coin_flip();
		result = ((result << 1)|a);
	}
	return (result%N) + 1;
}

void test()
{
	//pass
}
int times = 0;

int main()
{
	TOP:
	srand(time(NULL));
	/*unsigned int count0 = 0, count1 = 0;
	for (int i = 0; i < 97; i++)
	{
		unsigned int r = spry_coin_flip();
		if (r == 1)
			count1++;
		else
			count0++;
		std::cout << spry_coin_flip() << " ";
	}
	std::cout << std::endl << count1 << " " << count0<< std::endl;*/




	int array[number] = { 0 };

	int ran;
	for (int i = 0; i < 20000; i++)
	{
		ran = custom_spry_random(number);
		//std::cout << "return "<< ran << std::endl;
		array[ran - 1]++;
	}
	std::cout << std::endl;
	int j = 1;
	for (int i : array)
	{
		std::cout << "counts[" << j << "] = " << i <<  " " << std::fixed << std::setw(6) << std::setprecision(2) << (float(i)/ 20000.0 *100) << std::endl;
		j++;
	}

	//if (array[0] != array[1])
	//{
	//	times++;
	//	goto TOP;
	//}
	//
	//std::cout << "number of run : " << time;
	int c;
	std::cin >> c;

	if (c == 1)
	{
		goto TOP;
	}
	system("pause");
	return 0;
}
