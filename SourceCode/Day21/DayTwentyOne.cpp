#include "DayTwentyOne.h"
#include <iterator>
#include <map>

using std::back_inserter;
using std::map;
using std::sort;

const unsigned long long DayTwentyOneTask::GetPartOneCode(vector<string> input)
{
	vector<Food> foodList = GetFoodList(input);
	vector<Ingredient> allergenFreeIngredients = GetIngredientsWithoutAllergens(foodList);
	return CountOccurrences(allergenFreeIngredients, foodList);
}

const string DayTwentyOneTask::GetPartTwoCode(vector<string> input)
{
	vector<Food> foodList = GetFoodList(input); 
	vector<Ingredient> dangerList = GetDangerIngredients(foodList);

	string key;
	for (int i = 0, len = dangerList.size(); i < len; i++)
	{
		key += dangerList[i].name;
		if (i < len - 1)
		{
			key += ",";
		}
	}

	return key;
}

const vector<Food> DayTwentyOneTask::GetFoodList(vector<string>& input)
{
	vector<Food> food;
	copy(input.begin(), input.end(), back_inserter(food));
	return food;
}

const vector<Ingredient> DayTwentyOneTask::GetIngredientsWithoutAllergens(vector<Food>& foodEntries)
{
	vector<Ingredient> allIngredients = MatchAllIngredientsWithAllergens(foodEntries);

	vector<Ingredient> nonAllergens;
	for (auto it = allIngredients.begin(); it != allIngredients.end(); it++)
	{
		if (!it->CanBeAllergen())
		{
			nonAllergens.push_back(*it);
		}
	}

	return nonAllergens;
}

const vector<Ingredient> DayTwentyOneTask::GetIngredientsWithAllergens(vector<Food>& foodEntries)
{
	vector<Ingredient> allIngredients = MatchAllIngredientsWithAllergens(foodEntries);

	vector<Ingredient> nonAllergens;
	for (auto it = allIngredients.begin(); it != allIngredients.end(); it++)
	{
		if (it->CanBeAllergen())
		{
			nonAllergens.push_back(*it);
		}
	}

	return nonAllergens;
}

const vector<Ingredient> DayTwentyOneTask::MatchAllIngredientsWithAllergens(vector<Food>& foodEntries)
{
	map<string, vector<string>> possibleAllergens;

	for (int i = 0, outsideLen = foodEntries.size(); i < outsideLen; i++)
	{
		Food food = foodEntries[i];
		for (int j = 0, jLen = food.ingredients.size(); j < jLen; j++)
		{
			string foodKey = food.ingredients[j];
			bool keyExists = possibleAllergens.find(foodKey) != possibleAllergens.end();
			if (keyExists)
			{
				vector<string>& allergens = possibleAllergens[foodKey];
				possibleAllergens[foodKey] = MergeAllergenLists(allergens, food.allergens);
			}
			else
			{
				possibleAllergens[foodKey] = food.allergens;
			}
		}
	}

	for (auto it = possibleAllergens.begin(); it != possibleAllergens.end(); it++)
	{
		for (int i = 0, len = it->second.size(); i < len; i++)
		{
			vector<Food> foodWithAllergen = GetFoodWithAllergen(it->second[i], foodEntries);
			bool inEveryRecipe = false;
			for (int j = 0, jLen = foodWithAllergen.size(); j < jLen; j++)
			{
				inEveryRecipe = false;
				for (int k = 0, kLen = foodWithAllergen[j].ingredients.size(); k < kLen; k++)
				{
					if (foodWithAllergen[j].ingredients[k] == it->first)
					{
						inEveryRecipe = true;
						break;
					}
				}

				if (!inEveryRecipe)
				{
					break;
				}
			}

			if (!inEveryRecipe)
			{
				it->second.erase(it->second.begin() + i);
				len--;
				i--;
			}
		}
	}

	vector<Ingredient> ingredients;
	for (auto it = possibleAllergens.begin(); it != possibleAllergens.end(); it++)
	{
		Ingredient ingredient(it->first);
		ingredient.possibleAllergens = it->second;
		ingredients.push_back(ingredient);
	}

	return ingredients;
}

const vector<string> DayTwentyOneTask::MergeAllergenLists(vector<string>& a, vector<string>& b)
{
	vector<string> allergens;
	allergens.insert(allergens.end(), a.begin(), a.end());

	const int aSize = a.size();

	for (int i = 0, bSize = b.size(); i < bSize; i++)
	{
		string toCheck = b[i];
		bool duplicate = false;

		for (int j = 0; j < aSize; j++)
		{
			if (toCheck == a[j])
			{
				duplicate = true;
				break;
			}
		}

		if (!duplicate)
		{
			allergens.push_back(toCheck);
		}
	}

	return allergens;
}

const vector<Food> DayTwentyOneTask::GetFoodWithAllergen(string allergen, vector<Food>& allFood)
{
	vector<Food> foodList;

	for (int i = 0, len = allFood.size(); i < len; i++)
	{
		for (int j = 0, jLen = allFood[i].allergens.size(); j < jLen; j++)
		{
			if (allFood[i].allergens[j] == allergen)
			{
				foodList.push_back(allFood[i]);
				break;
			}
		}
	}

	return foodList;
}

const int DayTwentyOneTask::CountOccurrences(vector<Ingredient>& ingredientsToCount, vector<Food>& allRecipes)
{
	int count = 0;
	const int receipeLen = allRecipes.size();

	for (int i = 0, len = ingredientsToCount.size(); i < len; i++)
	{
		for (int j = 0; j < receipeLen; j++)
		{
			for (int k = 0, kLen = allRecipes[j].ingredients.size(); k < kLen; k++)
			{
				if (ingredientsToCount[i].name == allRecipes[j].ingredients[k])
				{
					count++;
				}
			}
		}
	}

	return count;
}

const vector<Ingredient> DayTwentyOneTask::GetDangerIngredients(vector<Food>& allReceipes)
{
	vector<Ingredient> allerginList = GetIngredientsWithAllergens(allReceipes);

	bool changesMade = true;
	vector<Ingredient> dangerList;

	while (changesMade)
	{
		changesMade = false;
		for (int i = 0, len = allerginList.size(); i < len; i++)
		{
			if (allerginList[i].possibleAllergens.size() == 1)
			{
				for (int j = 0; j < len; j++)
				{
					if (j != i)
					{
						for (int k = 0, kLen = allerginList[j].possibleAllergens.size(); k < kLen; k++)
						{
							if (allerginList[j].possibleAllergens[k] == allerginList[i].possibleAllergens[0])
							{
								allerginList[j].possibleAllergens.erase(allerginList[j].possibleAllergens.begin() + k);
								break;
							}
						}
					}
				}

				dangerList.push_back(allerginList[i]);
				allerginList.erase(allerginList.begin() + i);
				i--;
				len--;
				changesMade = true;
			}
		}
	}
	
	sort(dangerList.begin(), dangerList.end());
	return dangerList;
}
