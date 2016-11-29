/*
 Copyright (c) 2014, Robot Control and Pattern Recognition Group, Warsaw University of Technology
 All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
     * Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.
     * Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.
     * Neither the name of the Warsaw University of Technology nor the
       names of its contributors may be used to endorse or promote products
       derived from this software without specific prior written permission.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL <COPYright HOLDER> BE LIABLE FOR ANY
 DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "common_behavior/abstract_state.h"

#include "velma_core_cs_task_cs_msgs/Command.h"
#include "velma_core_cs_ve_body_msgs/Status.h"

namespace velma_core_cs_types {

class StateSafe : public StateBase<velma_core_cs_ve_body_msgs::Status, velma_core_cs_task_cs_msgs::Command> {
public:
    typedef velma_core_cs_ve_body_msgs::Status TYPE_BUF_LO;
    typedef velma_core_cs_task_cs_msgs::Command TYPE_BUF_HI;

    StateSafe() :
        StateBase("state_velma_core_cs_safe", "behavior_velma_core_cs_safe")
    {
    }

    bool checkInitialCondition(
                const TYPE_BUF_LO& buf_lo,
                const TYPE_BUF_HI& buf_hi,
                const std::vector<RTT::TaskContext*> &components,
                const std::string& prev_state_name,
                bool in_error) const
    {
        if (prev_state_name == "state_velma_core_cs_safe") {
            return false;
        }

        return true;
    }
};

};  // namespace velma_core_cs_types

REGISTER_STATE( velma_core_cs_ve_body_msgs::Status, velma_core_cs_task_cs_msgs::Command, velma_core_cs_types::StateSafe );
