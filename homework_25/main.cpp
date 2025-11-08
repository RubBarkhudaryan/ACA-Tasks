#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include "./matrix.h"
#include "./logger.h"

int main()
{
	/*
		//logger class created to make logs from matrix class objs and strings (TASK 57)

		Matrix	mat1(3);
		Matrix	mat2(3, 5);

		Logger	log("./temp/log1.txt");

		log.write("------------Matrix 1------------\n");
		log.write(mat1);
		log.write("--------------------------------\n");

		log.write("------------Matrix 2------------\n");
		log.write(mat2);
		log.write("--------------------------------\n");
	*/

	//logger class modified to read from logs/sources to create matrix class objs from files (TASK 58)

	Logger						log("./source/source1.txt");
	std::vector<std::string>	log_data = log.read();
	Matrix						mat(log_data);

	log.replace_file("./source/source2.txt");
	log_data = log.read();
	Matrix						mat2(log_data);

	mat.print();
	mat2.print();

	return (0);
}