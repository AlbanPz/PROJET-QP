#include "doctest.h"
#include "fauve.h"
#include <string>

using std::string;

TEST_CASE("Constructeur de Fauve") {
  Fauve fauve("Lion", 0, 0, 10, Mobile::TypeDeplacement::VERTI_HORI);
  CHECK(fauve.nom() == "Lion");
  CHECK(fauve.x() == 0);
  CHECK(fauve.y() == 0);
  CHECK(fauve.force() == 10);
  CHECK(fauve.typeDeplacement() == Mobile::TypeDeplacement::VERTI_HORI);
}

TEST_CASE("Fauve peut se déplacer sur position") {
  Fauve fauve("Lion", 0, 0, 10, Mobile::TypeDeplacement::VERTI_HORI);
  CHECK(fauve.peutSeDeplacerSurPosition(0, 1));  // Déplacement vertical
  CHECK(fauve.peutSeDeplacerSurPosition(1, 0));  // Déplacement horizontal
  CHECK(!fauve.peutSeDeplacerSurPosition(1, 1));  // Déplacement diagonal
}

TEST_CASE("Changement de position de Fauve") {
Fauve fauve("Lion", 0, 0, 10, Mobile::TypeDeplacement::VERTI_HORI);
fauve.changerPosition(1, 1);
CHECK(fauve.x() == 1);
CHECK(fauve.y() == 1);
}

TEST_CASE("Fauve avec déplacement diagonal") {
Fauve fauve("Tigre", 0, 0, 10, Mobile::TypeDeplacement::DIAGONALE);
CHECK(fauve.peutSeDeplacerSurPosition(0, 1)); // Déplacement vertical
CHECK(fauve.peutSeDeplacerSurPosition(1, 0)); // Déplacement horizontal
CHECK(fauve.peutSeDeplacerSurPosition(1, 1)); // Déplacement diagonal
}

TEST_CASE("Fauve avec force négative") {
Fauve fauve("Lion", 0, 0, -10, Mobile::TypeDeplacement::VERTI_HORI);
CHECK(fauve.force() == 0); // La force ne peut pas être négative
}
