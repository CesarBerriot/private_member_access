#pragma once

// for a basic demonstration see tests/basic.cpp

#define PMA_DECLARE(class_name, member_name) template struct private_member_access_internal::declare_private_offset_access<&class_name::member_name, class class_name##_##member_name##_private_offset_key>;
#define PMA_GET(class_name, member_name, member_type, class_instance_pointer) (class_instance_pointer->*(private_member_access_internal::get_private_offset<member_type class_name::*, class_name##_##member_name##_private_offset_key>::offset))

namespace private_member_access_internal
{	template <class offset_type, class key>
	struct get_private_offset
	{
		public:
			static inline offset_type offset = {};
	};

	template <auto offset_variable, class key>
	struct declare_private_offset_access
	{
		private:
			static inline auto x = get_private_offset<decltype(offset_variable), key>::offset = offset_variable;
	};
}
