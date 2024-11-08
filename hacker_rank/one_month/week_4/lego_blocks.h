// You have an infinite number of 4 types of lego blocks of sizes given as
// (depth x height x width):
//
// d	h	w
// 1	1	1
// 1	1	2
// 1	1	3
// 1	1	4
// Using these blocks, you want to make a wall of height n and width m.
// Features of the wall are:
//
//- The wall should not have any holes in it.
//- The wall you build should be one solid structure, so there should not be a
// straight vertical break across all rows of bricks.
//- The bricks must be laid horizontally.
//
// How many ways can the wall be built?
//
// Example:
//  Height (n) = 2
//  Width (m) = 3
// There are good layouts
// Bottom row: 1 x 4. Top row: 1 x 1, 1 x 2   => Good
// Bottom row: 1 x 1, 1 x 3. Top row: 1 x 2, 1 x 1 => Good
// Bottom row: 1 x 4. Top row: 1 x 4   => Good
// Bottom row: 1 x 4. Top row: 1 x 1, 1 x 1, 1 x 1   => Good
// Etc... result should be 9

#ifndef ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_4_LEGO_BLOCKS_H_
#define ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_4_LEGO_BLOCKS_H_

int LegoBlocks(int n, int m);

#endif  // ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_4_LEGO_BLOCKS_H_
