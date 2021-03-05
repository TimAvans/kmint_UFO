#pragma once

#include "kmint/play.hpp"

namespace kmint {
	namespace ufo {
		class emp : public play::map_bound_actor {
		public:
			emp(map::map_graph& g, map::map_node& initial_node);
			// wordt elke game tick aangeroepen
			void act(delta_time dt) override;
			ui::drawable const& drawable() const override { return drawable_; }
			// als incorporeal false is, doet de actor mee aan collision detection
			bool incorporeal() const override { return false; }
			// geeft de lengte van een zijde van de collision box van deze actor terug.
			// Belangrijk voor collision detection
			scalar collision_range() const override { return 16.0; }
			// geeft aan dat de tank andere actors kan zien
			bool perceptive() const override { return true; }
			// geeft het bereik aan waarbinnen een tank
			// andere actors kan waarnemen.
			scalar perception_range() const override { return 200.f; }

		private:
			play::image_drawable drawable_;
			delta_time t_since_move_{};
		};

	} // namespace ufo
} // namespace kmint
