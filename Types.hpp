#ifndef ORO_STDINT_TYPES_HPP
#define ORO_STDINT_TYPES_HPP

#include <stdint.h>

///// int8 /////
#ifdef ADD_INT8_TYPE
#ifdef ORO_CHANNEL_ELEMENT_HPP
    extern template class RTT::base::ChannelElement< int_least8_t >;
#endif
#ifdef CORELIB_DATASOURCE_HPP
    extern template class RTT::internal::DataSource< int_least8_t >;
    extern template class RTT::internal::AssignableDataSource< int_least8_t >;
#endif
#ifdef ORO_CORELIB_DATASOURCES_HPP
    extern template class RTT::internal::ValueDataSource< int_least8_t >;
    extern template class RTT::internal::ConstantDataSource< int_least8_t >;
    extern template class RTT::internal::ReferenceDataSource< int_least8_t >;
#endif
#ifdef ORO_INPUT_PORT_HPP
    extern template class RTT::OutputPort< int_least8_t >;
#endif
#ifdef ORO_OUTPUT_PORT_HPP
    extern template class RTT::InputPort< int_least8_t >;
#endif
#ifdef ORO_PROPERTY_HPP
    extern template class RTT::Property< int_least8_t >;
#endif
#ifdef ORO_CORELIB_ATTRIBUTE_HPP
    extern template class RTT::Attribute< int_least8_t >;
#endif
#endif

///// int16 /////
#ifdef ORO_CHANNEL_ELEMENT_HPP
    extern template class RTT::base::ChannelElement< int_least16_t >;
#endif
#ifdef CORELIB_DATASOURCE_HPP
    extern template class RTT::internal::DataSource< int_least16_t >;
    extern template class RTT::internal::AssignableDataSource< int_least16_t >;
#endif
#ifdef ORO_CORELIB_DATASOURCES_HPP
    extern template class RTT::internal::ValueDataSource< int_least16_t >;
    extern template class RTT::internal::ConstantDataSource< int_least16_t >;
    extern template class RTT::internal::ReferenceDataSource< int_least16_t >;
#endif
#ifdef ORO_INPUT_PORT_HPP
    extern template class RTT::OutputPort< int_least16_t >;
#endif
#ifdef ORO_OUTPUT_PORT_HPP
    extern template class RTT::InputPort< int_least16_t >;
#endif
#ifdef ORO_PROPERTY_HPP
    extern template class RTT::Property< int_least16_t >;
#endif
#ifdef ORO_CORELIB_ATTRIBUTE_HPP
    extern template class RTT::Attribute< int_least16_t >;
#endif

///// int32 /////
#ifdef ORO_CHANNEL_ELEMENT_HPP
    extern template class RTT::base::ChannelElement< int_least32_t >;
#endif
#ifdef CORELIB_DATASOURCE_HPP
    extern template class RTT::internal::DataSource< int_least32_t >;
    extern template class RTT::internal::AssignableDataSource< int_least32_t >;
#endif
#ifdef ORO_CORELIB_DATASOURCES_HPP
    extern template class RTT::internal::ValueDataSource< int_least32_t >;
    extern template class RTT::internal::ConstantDataSource< int_least32_t >;
    extern template class RTT::internal::ReferenceDataSource< int_least32_t >;
#endif
#ifdef ORO_INPUT_PORT_HPP
    extern template class RTT::OutputPort< int_least32_t >;
#endif
#ifdef ORO_OUTPUT_PORT_HPP
    extern template class RTT::InputPort< int_least32_t >;
#endif
#ifdef ORO_PROPERTY_HPP
    extern template class RTT::Property< int_least32_t >;
#endif
#ifdef ORO_CORELIB_ATTRIBUTE_HPP
    extern template class RTT::Attribute< int_least32_t >;
#endif

///// int64 /////
#ifdef ORO_CHANNEL_ELEMENT_HPP
    extern template class RTT::base::ChannelElement< int_least64_t >;
#endif
#ifdef CORELIB_DATASOURCE_HPP
    extern template class RTT::internal::DataSource< int_least64_t >;
    extern template class RTT::internal::AssignableDataSource< int_least64_t >;
#endif
#ifdef ORO_CORELIB_DATASOURCES_HPP
    extern template class RTT::internal::ValueDataSource< int_least64_t >;
    extern template class RTT::internal::ConstantDataSource< int_least64_t >;
    extern template class RTT::internal::ReferenceDataSource< int_least64_t >;
#endif
#ifdef ORO_INPUT_PORT_HPP
    extern template class RTT::OutputPort< int_least64_t >;
#endif
#ifdef ORO_OUTPUT_PORT_HPP
    extern template class RTT::InputPort< int_least64_t >;
#endif
#ifdef ORO_PROPERTY_HPP
    extern template class RTT::Property< int_least64_t >;
#endif
#ifdef ORO_CORELIB_ATTRIBUTE_HPP
    extern template class RTT::Attribute< int_least64_t >;
#endif

///// uint8 /////
#ifdef ADD_INT8_TYPE
#ifdef ORO_CHANNEL_ELEMENT_HPP
    extern template class RTT::base::ChannelElement< uint_least8_t >;
#endif
#ifdef CORELIB_DATASOURCE_HPP
    extern template class RTT::internal::DataSource< uint_least8_t >;
    extern template class RTT::internal::AssignableDataSource< uint_least8_t >;
#endif
#ifdef ORO_CORELIB_DATASOURCES_HPP
    extern template class RTT::internal::ValueDataSource< uint_least8_t >;
    extern template class RTT::internal::ConstantDataSource< uint_least8_t >;
    extern template class RTT::internal::ReferenceDataSource< uint_least8_t >;
#endif
#ifdef ORO_INPUT_PORT_HPP
    extern template class RTT::OutputPort< uint_least8_t >;
#endif
#ifdef ORO_OUTPUT_PORT_HPP
    extern template class RTT::InputPort< uint_least8_t >;
#endif
#ifdef ORO_PROPERTY_HPP
    extern template class RTT::Property< uint_least8_t >;
#endif
#ifdef ORO_CORELIB_ATTRIBUTE_HPP
    extern template class RTT::Attribute< uint_least8_t >;
#endif
#endif

///// uint16 /////
#ifdef ORO_CHANNEL_ELEMENT_HPP
    extern template class RTT::base::ChannelElement< uint_least16_t >;
#endif
#ifdef CORELIB_DATASOURCE_HPP
    extern template class RTT::internal::DataSource< uint_least16_t >;
    extern template class RTT::internal::AssignableDataSource< uint_least16_t >;
#endif
#ifdef ORO_CORELIB_DATASOURCES_HPP
    extern template class RTT::internal::ValueDataSource< uint_least16_t >;
    extern template class RTT::internal::ConstantDataSource< uint_least16_t >;
    extern template class RTT::internal::ReferenceDataSource< uint_least16_t >;
#endif
#ifdef ORO_INPUT_PORT_HPP
    extern template class RTT::OutputPort< uint_least16_t >;
#endif
#ifdef ORO_OUTPUT_PORT_HPP
    extern template class RTT::InputPort< uint_least16_t >;
#endif
#ifdef ORO_PROPERTY_HPP
    extern template class RTT::Property< uint_least16_t >;
#endif
#ifdef ORO_CORELIB_ATTRIBUTE_HPP
    extern template class RTT::Attribute< uint_least16_t >;
#endif

///// uint32 /////
#ifdef ORO_CHANNEL_ELEMENT_HPP
    extern template class RTT::base::ChannelElement< uint_least32_t >;
#endif
#ifdef CORELIB_DATASOURCE_HPP
    extern template class RTT::internal::DataSource< uint_least32_t >;
    extern template class RTT::internal::AssignableDataSource< uint_least32_t >;
#endif
#ifdef ORO_CORELIB_DATASOURCES_HPP
    extern template class RTT::internal::ValueDataSource< uint_least32_t >;
    extern template class RTT::internal::ConstantDataSource< uint_least32_t >;
    extern template class RTT::internal::ReferenceDataSource< uint_least32_t >;
#endif
#ifdef ORO_INPUT_PORT_HPP
    extern template class RTT::OutputPort< uint_least32_t >;
#endif
#ifdef ORO_OUTPUT_PORT_HPP
    extern template class RTT::InputPort< uint_least32_t >;
#endif
#ifdef ORO_PROPERTY_HPP
    extern template class RTT::Property< uint_least32_t >;
#endif
#ifdef ORO_CORELIB_ATTRIBUTE_HPP
    extern template class RTT::Attribute< uint_least32_t >;
#endif

///// uint64 /////
#ifdef ORO_CHANNEL_ELEMENT_HPP
    extern template class RTT::base::ChannelElement< uint_least64_t >;
#endif
#ifdef CORELIB_DATASOURCE_HPP
    extern template class RTT::internal::DataSource< uint_least64_t >;
    extern template class RTT::internal::AssignableDataSource< uint_least64_t >;
#endif
#ifdef ORO_CORELIB_DATASOURCES_HPP
    extern template class RTT::internal::ValueDataSource< uint_least64_t >;
    extern template class RTT::internal::ConstantDataSource< uint_least64_t >;
    extern template class RTT::internal::ReferenceDataSource< uint_least64_t >;
#endif
#ifdef ORO_INPUT_PORT_HPP
    extern template class RTT::OutputPort< uint_least64_t >;
#endif
#ifdef ORO_OUTPUT_PORT_HPP
    extern template class RTT::InputPort< uint_least64_t >;
#endif
#ifdef ORO_PROPERTY_HPP
    extern template class RTT::Property< uint_least64_t >;
#endif
#ifdef ORO_CORELIB_ATTRIBUTE_HPP
    extern template class RTT::Attribute< uint_least64_t >;
#endif

#endif
