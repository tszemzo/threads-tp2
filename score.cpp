#include "score.h"

Score::Score() {
	score = 0;
}

bool Score::add(int points) {
	std::unique_lock<std::mutex> lk(m);
	score += points;
	return true;
}

void Score::print_score() {
    std::cout << "Puntos de Beneficio acumulados: " << score << '\n';
}

Score::~Score() {}
