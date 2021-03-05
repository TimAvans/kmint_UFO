#pragma once
#include "state.hpp"

namespace kmint {
	namespace ufo {
		template <class entity_type>
		class state_machine
		{
		private:

			entity_type* owner_;
			state<entity_type>* current_state_;
			state<entity_type>* previous_state_;
			state<entity_type>* global_state_;

		public:
			state_machine(entity_type* owner) :owner_(owner), current_state_(NULL), global_state_(NULL) {}

			void SetCurrentState(state<entity_type>* s)
			{
				current_state_ = s;
			}

			void SetGlobalState(state<entity_type>* g)
			{
				global_state_ = g;
			}

			void Update() const
			{
				if (global_state_)
				{
					global_state_->execute(owner_);
				}

				if (current_state_)
				{
					current_state_->execute(owner_);
				}
			}

			void ChangeState(state<entity_type>* new_state)
			{
				if (new_state != current_state_) {
					previous_state_ = current_state_;

					current_state_->exit(owner_);
					current_state_ = new_state;
					current_state_->enter(owner_);
				}
			}

			state<entity_type>* CurrentState() const
			{
				return current_state_;
			}

			state<entity_type>* GlobalState() const
			{
				return global_state_;
			}

			void RevertToPreviousState() {
				ChangeState(previous_state_);
			}

		};
	}
}