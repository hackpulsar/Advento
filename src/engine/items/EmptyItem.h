#pragma once
#include "Item.h"

namespace Advento
{
	class EmptyItem :
		public Engine::Item
	{
	public:
		EmptyItem();
		~EmptyItem();

		Item getHalf() override;
	};
}
