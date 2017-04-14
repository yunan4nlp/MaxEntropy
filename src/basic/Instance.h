#ifndef _INSTANCE_H_
#define _INSTANCE_H_

#include <iostream>
using namespace std;

class Instance
{
public:
	void clear()
	{
		m_tweet.clear();
		m_label.clear();
	}

	void evaluate(const string& predict_label, Metric& eval) const
	{
		if (predict_label == m_label)
			eval.correct_label_count++;
		eval.overall_label_count++;
	}

	void copyValuesFrom(const Instance& anInstance)
	{
		allocate(anInstance.size());
		m_label = anInstance.m_label;
		m_tweet = anInstance.m_tweet;
	}

	void assignLabel(const string& resulted_label) {
		m_label = resulted_label;
	}

	int size() const {
		return m_tweet.size();
	}

	void allocate(int length)
	{
		clear();
		m_tweet.resize(length);
	}
public:
	vector<string> m_tweet;
	string m_label;
};

#endif /*_INSTANCE_H_*/
