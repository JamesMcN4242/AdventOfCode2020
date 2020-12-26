#pragma once

#include "../InputGrabber/InputGrabber.h"
#include <algorithm>
#include <string>
#include <vector>

using std::remove_if;
using std::string;
using std::vector;

struct Ingredient
{
public:
	Ingredient(string ingredientName) : name(ingredientName) {}
	bool CanBeAllergen() { return possibleAllergens.size() > 0; }
	bool operator<(const Ingredient& a) const
	{
		return possibleAllergens[0] < a.possibleAllergens[0];
	}

	string name;
	vector<string> possibleAllergens;
};

struct Food
{
public:
	Food(string input = "")
	{
		string ingredientList = input.substr(0, input.find('(') - 1);
		ingredients = InputGrabber::GetEachLine(ingredientList, ' ');

		int startIndex = ingredientList.size() + 10;
		string allergenList = input.substr(startIndex, input.find(')') - startIndex);
		allergenList.erase(remove_if(allergenList.begin(), allergenList.end(), isspace), allergenList.end());
		allergens = InputGrabber::GetEachLine(allergenList, ',');
	}

	vector<string> ingredients;
	vector<string> allergens;
};

class DayTwentyOneTask
{
public:
	static const unsigned long long GetPartOneCode(vector<string> input);
	static const string GetPartTwoCode(vector<string> input);
private:
	static const vector<Food> GetFoodList(vector<string>& input);
	static const vector<Ingredient> GetIngredientsWithoutAllergens(vector<Food>& foodEntries);
	static const vector<Ingredient> GetIngredientsWithAllergens(vector<Food>& foodEntries);
	static const vector<Ingredient> MatchAllIngredientsWithAllergens(vector<Food>& foodEntries);
	static const vector<string> MergeAllergenLists(vector<string>& a, vector<string>& b);
	static const vector<Food> GetFoodWithAllergen(string allergen, vector<Food>& allFood);
	static const int CountOccurrences(vector<Ingredient>& ingredientsToCount, vector<Food>& allRecipes);
	static const vector<Ingredient> GetDangerIngredients(vector<Food>& allReceipes);
};