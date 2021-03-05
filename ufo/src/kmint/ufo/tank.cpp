#include "kmint/ufo/tank.hpp"
#include "kmint/graphics.hpp"
#include "kmint/ufo/node_algorithm.hpp"
#include "kmint/random.hpp"

#include "kmint/ufo/global_tank_state.hpp"

#include <iostream>

namespace kmint::ufo {

namespace {
graphics::image tank_image(tank_type t) {
  constexpr scalar scale = 0.35;
  switch (t) {
  case tank_type::red:
    return graphics::image{"resources/tank_red.png", scale};
  case tank_type::green:
    return graphics::image{"resources/tank_green.png", scale};
  }
  return graphics::image{"resources/tank_green.png", scale};
}


} // namespace

tank::tank(map::map_graph& g, map::map_node& initial_node, tank_type t) : state_user{g, initial_node, graphics::image{tank_image(t)}}
{
	state_machine_->SetGlobalState(global_tank_state::Instance());
}

void tank::act(delta_time dt) {
	t_since_move_ += dt;
	if (to_seconds(t_since_move_) >= waiting_time(node())) {
		get_state_machine()->Update();
		t_since_move_ = from_seconds(0);
	}
	// laat ook zien wat hij ziet
	for (auto i = begin_perceived(); i != end_perceived(); ++i) {
		auto const& a = *i;
		//std::cout << "Saw something at " << a.location().x() << ", "
		//	<< a.location().y() << "\n";
	}
}

} // namespace kmint::ufo
