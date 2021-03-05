#pragma once
#include "state.hpp"
#include "kmint/play.hpp"

namespace kmint {
	namespace ufo {
		class global_tank_state : public state<play::map_bound_actor> {
		public:
			static global_tank_state* Instance();
			void execute(play::map_bound_actor* actor) override;
			void enter(play::map_bound_actor* actor) override;
			void exit(play::map_bound_actor* actor) override;
		private:
			global_tank_state() {}
		};
	}
}