#include "doctest.h"
#include "fauve.h"
#include <string>

using std::string;

TEST_CASE("Constructeur de Fauve") {
  Fauve fauve("Lion", 0, 0, 10, Mobile::TypeDeplacement::VERTI_HORI);
  REQUIRE_EQ(fauve.nom(), "Lion");
  REQUIRE_EQ(fauve.x(), 0);
  REQUIRE_EQ(fauve.y(), 0);
  REQUIRE_EQ(fauve.force(), 10);
  REQUIRE_EQ(fauve.typeDeplacement(), Mobile::TypeDeplacement::VERTI_HORI);
}

TEST_CASE("Fauve peut se déplacer sur position") {
  Fauve fauve("Lion", 0, 0, 10, Mobile::TypeDeplacement::VERTI_HORI);
  REQUIRE_EQ(fauve.peutSeDeplacerSurPosition(0, 1), true);  // Déplacement vertical
  REQUIRE_EQ(fauve.peutSeDeplacerSurPosition(1, 0), true);  // Déplacement horizontal
  REQUIRE_EQ(fauve.peutSeDeplacerSurPosition(1, 1), false);  // Déplacement diagonal
}

TEST_CASE("Changement de position de Fauve") {
  Fauve fauve("Lion", 0, 0, 10, Mobile::TypeDeplacement::VERTI_HORI);
  fauve.changerPosition(1, 1);
  REQUIRE_EQ(fauve.x(), 1);
  REQUIRE_EQ(fauve.y(), 1);
}

TEST_CASE("Fauve avec déplacement diagonal") {
  Fauve fauve("Tigre", 0, 0, 10, Mobile::TypeDeplacement::DIAGONALE);
  REQUIRE_EQ(fauve.peutSeDeplacerSurPosition(0, 1), true); // Déplacement vertical
  REQUIRE_EQ(fauve.peutSeDeplacerSurPosition(1, 0), true); // Déplacement horizontal
  REQUIRE_EQ(fauve.peutSeDeplacerSurPosition(1, 1), true); // Déplacement diagonal
}

TEST_CASE("Fauve avec force négative") {
  Fauve fauve("Lion", 0, 0, -10, Mobile::TypeDeplacement::VERTI_HORI);
  REQUIRE_EQ(fauve.force(), 0); // La force ne peut pas être négative
}
