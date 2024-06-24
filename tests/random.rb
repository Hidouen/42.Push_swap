#!/usr/bin/ruby

if ARGV.length != 3
	puts "random.rb: wrong number of arguments, requires 3 integers \n\t- usage: random.rb [min value] [max value] [number of values]"
	exit 1
end

if	ARGV[0].to_i >= ARGV[1].to_i
	puts "random.rb: min value must be less than max value"
	exit 1
end

if	ARGV[2].to_i <= 0
	puts "random.rb: number of values must be greater than 0"
	exit 1
end

puts (ARGV[0].to_i..ARGV[1].to_i).to_a.sample(ARGV[2].to_i).join(' ')
