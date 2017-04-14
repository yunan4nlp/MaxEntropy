#ifndef SRC_ModelParams_H_
#define SRC_ModelParams_H_
#include "HyperParams.h"

// Each model consists of two parts, building neural graph and defining output losses.
class ModelParams{

public:
	SparseParams sparse_layer;

public:
	Alphabet labelAlpha; // should be initialized outside
	Alphabet linearAlpha;
	SoftMaxLoss loss;


public:
	bool initial(HyperParams& opts, AlignedMemoryPool* mem = NULL){

		// some model parameters should be initialized outside
		if (linearAlpha.size() <= 0 || labelAlpha.size() <= 0){
			return false;
		}
		opts.labelSize = labelAlpha.size();
		opts.linearfeatsize = linearAlpha.size();

		sparse_layer.initial(&linearAlpha, opts.labelSize);
		return true;
	}


	void exportModelParams(ModelUpdate& ada){
		sparse_layer.exportAdaParams(ada);
	}


	void exportCheckGradParams(CheckGrad& checkgrad){
		checkgrad.add(&sparse_layer.W, "sparse_layer.W");
	}

	// will add it later
	void saveModel(){

	}

	void loadModel(const string& inFile){

	}

};

#endif /* SRC_ModelParams_H_ */