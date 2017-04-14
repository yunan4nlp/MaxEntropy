#ifndef _PARSER_OPTIONS_
#define _PARSER_OPTIONS_

#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include "N3L.h"

using namespace std;

class Options {
public:
  int featCutOff;
  dtype initRange;
  int maxIter;
  int batchSize;
  dtype adaEps;
  dtype adaAlpha;
  dtype regParameter;
  dtype dropProb;

  int verboseIter;
  bool saveIntermediate;
  bool train;
  int maxInstance;
  vector<string> testFiles;
  string outBest;

  Options() {
    featCutOff = 0;
    initRange = 0.01;
    maxIter = 1000;
    batchSize = 1;
    adaEps = 1e-6;
    adaAlpha = 0.01;
    regParameter = 1e-8;
    dropProb = -1;

    verboseIter = 100;
    saveIntermediate = true;
    train = false;
    maxInstance = -1;
    testFiles.clear();
    outBest = "";
  }

  virtual ~Options() {

  }

  void setOptions(const vector<string> &vecOption) {
    int i = 0;
    for (; i < vecOption.size(); ++i) {
      pair<string, string> pr;
      string2pair(vecOption[i], pr, '=');
      if (pr.first == "featCutOff")
        featCutOff = atoi(pr.second.c_str());
      if (pr.first == "initRange")
        initRange = atof(pr.second.c_str());
      if (pr.first == "maxIter")
        maxIter = atoi(pr.second.c_str());
      if (pr.first == "batchSize")
        batchSize = atoi(pr.second.c_str());
      if (pr.first == "adaEps")
        adaEps = atof(pr.second.c_str());
      if (pr.first == "adaAlpha")
        adaAlpha = atof(pr.second.c_str());
      if (pr.first == "regParameter")
        regParameter = atof(pr.second.c_str());
      if (pr.first == "dropProb")
        dropProb = atof(pr.second.c_str());

        
      if (pr.first == "verboseIter")
        verboseIter = atoi(pr.second.c_str());
      if (pr.first == "train")
        train = (pr.second == "true") ? true : false;
      if (pr.first == "saveIntermediate")
        saveIntermediate = (pr.second == "true") ? true : false;
      if (pr.first == "maxInstance")
        maxInstance = atoi(pr.second.c_str());
      if (pr.first == "testFile")
        testFiles.push_back(pr.second);
      if (pr.first == "outBest")
        outBest = pr.second;
    }
  }

  void showOptions() {
    std::cout << "featCutOff = " << featCutOff << std::endl;
    std::cout << "initRange = " << initRange << std::endl;
    std::cout << "maxIter = " << maxIter << std::endl;
    std::cout << "batchSize = " << batchSize << std::endl;
    std::cout << "adaEps = " << adaEps << std::endl;
    std::cout << "adaAlpha = " << adaAlpha << std::endl;
    std::cout << "regParameter = " << regParameter << std::endl;
    std::cout << "dropProb = " << dropProb << std::endl;


    std::cout << "verboseIter = " << verboseIter << std::endl;
    std::cout << "saveItermediate = " << saveIntermediate << std::endl;
    std::cout << "train = " << train << std::endl;
    std::cout << "maxInstance = " << maxInstance << std::endl;
    for (int idx = 0; idx < testFiles.size(); idx++) {
      std::cout << "testFile = " << testFiles[idx] << std::endl;
    }
    std::cout << "outBest = " << outBest << std::endl;
  }

  void load(const std::string& infile) {
    ifstream inf;
    inf.open(infile.c_str());
    vector<string> vecLine;
    while (1) {
      string strLine;
      if (!my_getline(inf, strLine)) {
        break;
      }
      if (strLine.empty())
        continue;
      vecLine.push_back(strLine);
    }
    inf.close();
    setOptions(vecLine);
  }
};

#endif

