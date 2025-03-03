#pragma once

#ifndef TETRIS__BAG_RANDOMIZER__HPP
#define TETRIS__BAG_RANDOMIZER__HPP

#include <algorithm>
#include <random>
#include <vector>

namespace Tetris
{
	/// <summary>
	/// Implements bag randomization, allowing a programmer to insert items, randomly shuffle them into a bag, and retrieve them one by one until the bag is empty.
	/// </summary>
	template<class T>
	class BagRandomizer
	{
	private:

		std::vector<T> items;
		std::vector<T> bag;
		std::mt19937 rng;

	public:

		BagRandomizer()
			: rng(std::random_device{}()) {
		}

		// Refill the bag with the items.
		void refillBag()
		{
			if (this->items.empty()) {
				throw std::runtime_error("No items added to the bag!");
			}
			this->bag = this->items;
			std::shuffle(this->bag.begin(), this->bag.end(), this->rng);
		}

		// Put new items to the bag.
		void setItems(
			const std::vector<T>& items)
		{
			this->items = items;
		}

		// Pull an item from the bag.
		T pullItem()
		{
			if (this->bag.empty()) {
				this->refillBag();
			}

			const T item = this->bag.back();

			this->bag.pop_back();
			return item;
		}

		// Check the size of the bag.
		bool size() const
		{
			return this->bag.size();
		}

		// Check if the bag is empty.
		bool isEmpty() const
		{
			return this->bag.empty();
		}
	};
}

#endif
