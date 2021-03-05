#pragma once
#include "state.hpp"
#include <kmint\play\actor.hpp>

namespace kmint {
	namespace ufo {
		class wander_state : public state<play::map_bound_actor> {
		public:
			static wander_state* Instance();
			void execute(play::map_bound_actor* actor) override;
			void enter(play::map_bound_actor* actor) override;
			void exit(play::map_bound_actor* actor) override;
		private:
			wander_state() {}


		};
	}
}