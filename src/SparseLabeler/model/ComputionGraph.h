#ifndef SRC_ComputionGraph_H_
#define SRC_ComputionGraph_H_

#include "ModelParams.h"


// Each model consists of two parts, building neural graph and defining output losses.
struct ComputionGraph : Graph{
public:
	// node instances
	SparseNode _output;
public:
	ComputionGraph() : Graph(){
	}

	~ComputionGraph(){
		clear();
	}

public:

	inline void clear(){
		Graph::clear();
	}

public:
	inline void initial(ModelParams& model, HyperParams& opts, AlignedMemoryPool* mem = NULL){
		_output.setParam(&model.sparse_layer);
		_output.init(opts.labelSize, -1, mem);
	}
	

public:
	// some nodes may behave different during training and decode, for example, dropout
	inline void forward(const Feature& feature, bool bTrain = false){
		//first step: clear value
		clearValue(bTrain); // compute is a must step for train, predict and cost computation

		// second step: build graph

		//forward
		_output.forward(this, feature.m_linear_features);
	}

};

#endif /* SRC_ComputionGraph_H_ */