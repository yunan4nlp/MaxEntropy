#ifndef _EXAMPLE_H_
#define _EXAMPLE_H_

#include <iostream>
#include <vector>

using namespace std;

class Feature
{
public:
	vector<string> m_tweet_words;
	vector<string> m_linear_features;
public:
	void clear()
	{
		m_tweet_words.clear();
		m_linear_features.clear();
	}
};

class Example
{
public:
	Feature m_feature;
	vector<double> m_label;

public:
	void clear()
	{
		m_feature.clear();
		m_label.clear();
	}
};

#endif /*_EXAMPLE_H_*/