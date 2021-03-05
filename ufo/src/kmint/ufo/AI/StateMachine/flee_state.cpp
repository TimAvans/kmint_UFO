#include "kmint/ufo/flee_state.hpp"

#include "kmint/play.hpp"
#include <kmint/random.hpp>
#include <kmint/ufo/state_user.hpp>

namespace kmint {
	namespace ufo {

		flee_state* flee_state::Instance()
		{
			static flee_state instance;
			return &instance;
		}

		void flee_state::enter(play::map_bound_actor* actor) {
			auto x = dynamic_cast<state_user*>(actor);
			x->change_color(255, 0, 255);
		}

		void flee_state::execute(play::map_bound_actor* actor)
		{

		}

		void flee_state::exit(play::map_bound_actor* actor) {
			auto x = dynamic_cast<state_user*>(actor);
			x->clear_color();
		}
	}
}



