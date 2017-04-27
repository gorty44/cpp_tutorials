#ifndef GENERIC_BUILDER_TEST_HPP_
#define GENERIC_BUILDER_TEST_HPP_

#include "gtest/gtest.h"
#include "generic_builder.hpp"
#include "messaging.hpp"

TEST(BuilderTest, createBuilderDecoratorWithDefaultAdapter) {

	GenericBuilder<MessageBuilder> builder;
	Message m = builder.build();

	std::string actual = m.message();
	EXPECT_STREQ("", actual.c_str());
}

TEST(BuilderTest, createBuilderDecorator) {

	GenericBuilder<MessageBuilder, MessageBuilderAdapter> builder;
	Message m = builder.build();

	std::string actual = m.message();
	EXPECT_STREQ("A message adapter to customize the message body", actual.c_str());
}

#endif // GENERIC_BUILDER_TEST_HPP_
