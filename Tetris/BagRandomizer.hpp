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
	/// <typeparam name="T">Type of the bag elements.</typeparam>
	template<class T>
	class BagRandomizer
	{
	private:

		std::vector<T> items;
		std::vector<T> bag;
		std::mt19937 rng;

	public:

		/// <summary>
		/// Initializes a new instance of the BagRandomizer class.
		/// </summary>
		BagRandomizer()
			: rng(std::random_device{}()) {
		}

		/// <summary>
		/// Refills the bag with the items.
		/// </summary>
		void refillBag()
		{
			if (this->items.empty()) {
				throw std::runtime_error("No items added to the bag!");
			}
			this->bag = this->items;
			std::shuffle(this->bag.begin(), this->bag.end(), this->rng);
		}

		/// <summary>
		/// Puts new items to the bag.
		/// </summary>
		/// <param name="items">- the items for the bag.</param>
		void setItems(
			const std::vector<T>& items)
		{
			this->items = items;
		}

		/// <summary>
		/// Pulls an item from the bag.
		/// </summary>
		/// <returns>the last bag item.</returns>
		T pullItem()
		{
			if (this->bag.empty()) {
				this->refillBag();
			}

			const T item = this->bag.back();

			this->bag.pop_back();
			return item;
		}

		/// <returns>current size of the bag.</returns>
		bool size() const
		{
			return this->bag.size();
		}

		/// <summary>
		/// Checks if the bag is empty.
		/// </summary>
		bool isEmpty() const
		{
			return this->bag.empty();
		}
	};
}

#endif
