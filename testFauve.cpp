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
