// Copyright (C) 2009-2016 ETH Zurich
// Copyright (C) 2007?-2016 Center for Nanophase Materials Sciences, ORNL
// All rights reserved.
//
// See LICENSE.txt for terms of usage.
// See CITATION.txt for citation guidelines if you use this code for scientific publications.
//
// Author: Urs R. Haehner (haehneru@itp.phys.ethz.ch)
//
// This file tests the CT-AUX specialization of the McSolverParameters class.
//
// TODO: Add tests for get_buffer_size, pack, unpack and writing.

#include "dca/phys/parameters/mc_solver_parameters.hpp"
#include "gtest/gtest.h"
#include "dca/io/json/json_reader.hpp"

TEST(McSolverParametersCtAuxTest, DefaultValues) {
  dca::phys::params::McSolverParameters<dca::phys::solver::CT_AUX> pars;

  EXPECT_EQ(1., pars.get_expansion_parameter_K());
  EXPECT_EQ(128, pars.get_initial_matrix_size());
  EXPECT_EQ(64, pars.get_submatrix_size());
  EXPECT_FALSE(pars.additional_time_measurements());
  EXPECT_EQ(0, pars.time_intervals_for_time_measurements());
}

TEST(McSolverParametersCtAuxTest, ReadAll) {
  dca::io::JSONReader reader;
  dca::phys::params::McSolverParameters<dca::phys::solver::CT_AUX> pars;

  reader.open_file(DCA_SOURCE_DIR
                   "/test/unit/phys/parameters/mc_solver_parameters/input_read_all_ct_aux.json");
  pars.readWrite(reader);
  reader.close_file();

  EXPECT_EQ(10., pars.get_expansion_parameter_K());
  EXPECT_EQ(64, pars.get_initial_matrix_size());
  EXPECT_EQ(32, pars.get_submatrix_size());
  EXPECT_TRUE(pars.additional_time_measurements());
  EXPECT_EQ(128, pars.time_intervals_for_time_measurements());
}
