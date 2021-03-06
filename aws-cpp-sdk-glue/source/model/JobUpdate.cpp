﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#include <aws/glue/model/JobUpdate.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace Glue
{
namespace Model
{

JobUpdate::JobUpdate() : 
    m_descriptionHasBeenSet(false),
    m_logUriHasBeenSet(false),
    m_roleHasBeenSet(false),
    m_executionPropertyHasBeenSet(false),
    m_commandHasBeenSet(false),
    m_defaultArgumentsHasBeenSet(false),
    m_connectionsHasBeenSet(false),
    m_maxRetries(0),
    m_maxRetriesHasBeenSet(false),
    m_allocatedCapacity(0),
    m_allocatedCapacityHasBeenSet(false),
    m_timeout(0),
    m_timeoutHasBeenSet(false)
{
}

JobUpdate::JobUpdate(const JsonValue& jsonValue) : 
    m_descriptionHasBeenSet(false),
    m_logUriHasBeenSet(false),
    m_roleHasBeenSet(false),
    m_executionPropertyHasBeenSet(false),
    m_commandHasBeenSet(false),
    m_defaultArgumentsHasBeenSet(false),
    m_connectionsHasBeenSet(false),
    m_maxRetries(0),
    m_maxRetriesHasBeenSet(false),
    m_allocatedCapacity(0),
    m_allocatedCapacityHasBeenSet(false),
    m_timeout(0),
    m_timeoutHasBeenSet(false)
{
  *this = jsonValue;
}

JobUpdate& JobUpdate::operator =(const JsonValue& jsonValue)
{
  if(jsonValue.ValueExists("Description"))
  {
    m_description = jsonValue.GetString("Description");

    m_descriptionHasBeenSet = true;
  }

  if(jsonValue.ValueExists("LogUri"))
  {
    m_logUri = jsonValue.GetString("LogUri");

    m_logUriHasBeenSet = true;
  }

  if(jsonValue.ValueExists("Role"))
  {
    m_role = jsonValue.GetString("Role");

    m_roleHasBeenSet = true;
  }

  if(jsonValue.ValueExists("ExecutionProperty"))
  {
    m_executionProperty = jsonValue.GetObject("ExecutionProperty");

    m_executionPropertyHasBeenSet = true;
  }

  if(jsonValue.ValueExists("Command"))
  {
    m_command = jsonValue.GetObject("Command");

    m_commandHasBeenSet = true;
  }

  if(jsonValue.ValueExists("DefaultArguments"))
  {
    Aws::Map<Aws::String, JsonValue> defaultArgumentsJsonMap = jsonValue.GetObject("DefaultArguments").GetAllObjects();
    for(auto& defaultArgumentsItem : defaultArgumentsJsonMap)
    {
      m_defaultArguments[defaultArgumentsItem.first] = defaultArgumentsItem.second.AsString();
    }
    m_defaultArgumentsHasBeenSet = true;
  }

  if(jsonValue.ValueExists("Connections"))
  {
    m_connections = jsonValue.GetObject("Connections");

    m_connectionsHasBeenSet = true;
  }

  if(jsonValue.ValueExists("MaxRetries"))
  {
    m_maxRetries = jsonValue.GetInteger("MaxRetries");

    m_maxRetriesHasBeenSet = true;
  }

  if(jsonValue.ValueExists("AllocatedCapacity"))
  {
    m_allocatedCapacity = jsonValue.GetInteger("AllocatedCapacity");

    m_allocatedCapacityHasBeenSet = true;
  }

  if(jsonValue.ValueExists("Timeout"))
  {
    m_timeout = jsonValue.GetInteger("Timeout");

    m_timeoutHasBeenSet = true;
  }

  return *this;
}

JsonValue JobUpdate::Jsonize() const
{
  JsonValue payload;

  if(m_descriptionHasBeenSet)
  {
   payload.WithString("Description", m_description);

  }

  if(m_logUriHasBeenSet)
  {
   payload.WithString("LogUri", m_logUri);

  }

  if(m_roleHasBeenSet)
  {
   payload.WithString("Role", m_role);

  }

  if(m_executionPropertyHasBeenSet)
  {
   payload.WithObject("ExecutionProperty", m_executionProperty.Jsonize());

  }

  if(m_commandHasBeenSet)
  {
   payload.WithObject("Command", m_command.Jsonize());

  }

  if(m_defaultArgumentsHasBeenSet)
  {
   JsonValue defaultArgumentsJsonMap;
   for(auto& defaultArgumentsItem : m_defaultArguments)
   {
     defaultArgumentsJsonMap.WithString(defaultArgumentsItem.first, defaultArgumentsItem.second);
   }
   payload.WithObject("DefaultArguments", std::move(defaultArgumentsJsonMap));

  }

  if(m_connectionsHasBeenSet)
  {
   payload.WithObject("Connections", m_connections.Jsonize());

  }

  if(m_maxRetriesHasBeenSet)
  {
   payload.WithInteger("MaxRetries", m_maxRetries);

  }

  if(m_allocatedCapacityHasBeenSet)
  {
   payload.WithInteger("AllocatedCapacity", m_allocatedCapacity);

  }

  if(m_timeoutHasBeenSet)
  {
   payload.WithInteger("Timeout", m_timeout);

  }

  return payload;
}

} // namespace Model
} // namespace Glue
} // namespace Aws
