/* -*- c++ -*- */
/* 
 * Copyright 2017 Phil Frost.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_RADIOTELETYPE_ASYNC_WORD_EXTRACTOR_BB_IMPL_H
#define INCLUDED_RADIOTELETYPE_ASYNC_WORD_EXTRACTOR_BB_IMPL_H

#include <radioteletype/async_word_extractor_bb.h>

namespace gr {
  namespace radioteletype {

    class async_word_extractor_bb_impl : public async_word_extractor_bb
    {
      private:
        char bits_per_word;
        float bits_per_sample;
        float position;
        bool waiting_for_start;
        bool verify_start;
        unsigned char current_word;
        unsigned char bits_eaten;
        void reset();
        unsigned char *eat_sample(signed char sample, unsigned char *out);
        unsigned char *eat_bit(signed char bit, unsigned char *out);

      public:
        async_word_extractor_bb_impl(int bits_per_word, float sample_rate, float bit_rate);
        ~async_word_extractor_bb_impl();

        // Where all the action really happens
        void forecast (int noutput_items, gr_vector_int &ninput_items_required);

        int general_work(int noutput_items,
            gr_vector_int &ninput_items,
            gr_vector_const_void_star &input_items,
            gr_vector_void_star &output_items);
    };

  } // namespace radioteletype
} // namespace gr

#endif /* INCLUDED_RADIOTELETYPE_ASYNC_WORD_EXTRACTOR_BB_IMPL_H */

