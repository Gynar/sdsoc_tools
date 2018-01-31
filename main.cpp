#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>

enum t_conv_type {
	One_to_N,
	N_to_N
};

int test(int argc, char** argv) {
	std::ifstream fConfig, fBias, fWeight, fInput;
	std::ofstream fOutput;

	int nInputPl, nOutputPl, nInputWidth, nMaskWidth;
	int nInputSize, nOutputSize, nOutputWidth;

	t_conv_type conv_type;
	std::vector<std::string> vec_substr;

	if (argc != 6) {
		std::cout << "invalid args, arguments : (config, bias, weight, input) files" << std::endl;
		return 0;
	}

	fConfig.open(argv[2]);
	fBias.open(argv[3]);
	fWeight.open(argv[4]);
	fInput.open(argv[5]);
	fOutput.open("mat_output");

	if (fConfig.is_open() && fBias.is_open() && fWeight.is_open() && fInput.is_open())
		std::cout << "file opened." << std::endl;
	else {
		std::cout << "file open failed." << std::endl;
		return 0;
	}

	// read config file
	for (int n = 0; n < 4; n++) {
		std::string str_tmp;
		if (getline(fConfig, str_tmp, ' ')) {
			vec_substr.push_back(str_tmp);
		}
	}

	if (vec_substr.size() != 4)
		std::cout << "config failed" << std::endl;
	else {
		//
		nInputPl = atoi(vec_substr[0].c_str());
		nOutputPl = atoi(vec_substr[1].c_str());
		nInputWidth = atoi(vec_substr[2].c_str());
		nMaskWidth = atoi(vec_substr[3].c_str());
		//
		std::cout << "nInputPl : " << nInputPl << std::endl;
		std::cout << "nOutputPl : " << nOutputPl << std::endl;
		std::cout << "nInputWidth : " << nInputWidth << std::endl;
		std::cout << "nMaskWidth : " << nMaskWidth << std::endl;
	}

	if (nInputPl == 1)
		conv_type = One_to_N;
	else
		conv_type = N_to_N;

	nInputSize = nInputWidth*nInputWidth;
	nOutputWidth = nInputWidth - (nMaskWidth - 1);
	nOutputSize = nOutputWidth*nOutputWidth;

	// read bias file : output size

	for(int n = 0; n < nOutputSize; n++)

	//while(fgetc(pBias) != '{');

	// read weight file : (input plane x output plane x mask size) or (output plane x mask size)
	//while(fgetc(pBias) != '{');

	// read input file : (input plane x input size) or (input size)
	//while(fgetc(pBias) != '{');

	// conv test

	// write output file

	fConfig.close();
	fBias.close();
	fWeight.close();
	fInput.close();
	fOutput.close();

	return 0;
}

int generate(int argc, char** argv) {

	return 0;
}

int main(int argc, char** argv) {
	int opt;

	if (argc < 2) {
		std::cout << "specify test/generate mode" << std::endl;
		std::cout << "TEST     : cmpncheck test [config_file] [bias_file] [weight_file] [input_file]" << std::endl;
		std::cout << "GENERATE : cmpncheck gen [nPlane] [nWidth]" << std::endl;
	}

	if (!strcmp(argv[1], "test"))
		opt = 0;
	else if (!strcmp(argv[1], "gen"))
		opt = 1;
	else
		opt = -1;

	switch (opt) {
	case 0:
		test(argc, argv);
		break;
	case 1:
		generate(argc, argv);
		break;
	default:
		std::cout << "undefined mode" << std::endl;
		break;
	}

	return 0;
}
