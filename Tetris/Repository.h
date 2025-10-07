#pragma once

#include <vector>
#include <algorithm>
#include <fstream>
#include "Score.h"

class RepoException {
	std::string msg;
public:
	RepoException(std::string m) :msg{ m } {}
	std::string getMsg()const { return msg; }
};

class Repository {
private:
	std::vector<Score> scores;

public:
	Repository()=default;
	~Repository()=default;

	void save(const Score &score) ;
	void update(const Score &score) ;
	const Score& find(const std::string &name) const;
	const std::vector<Score>& all() const;

};

class RepoFile: public Repository {
private:
	std::string fileName;

	void loadFromFile();
	void saveToFile();

public:
	RepoFile(std::string fileName) :Repository(), fileName{ fileName } {
		loadFromFile();
	}

	void save(const Score &score) {
		Repository::save(score);
		saveToFile();
	}

	void update(const Score &score) {
		Repository::update(score);
		saveToFile();
	}
};

