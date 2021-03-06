# frozen_string_literal: true

# Arrays - Get Products of all other elements in Ruby

# Generates prefix products
def build_prefix_products(nums)
  prefix_products = []

  nums.each do |num|
    if prefix_products.count.positive?
      prefix_products.append(prefix_products.last * num)
    else
      prefix_products.append(num)
    end
  end

  prefix_products
end

# Generates suffix products
def build_suffix_products(nums)
  suffix_products = []

  nums.reverse.each do |num|
    if suffix_products.count.positive?
      suffix_products.append(suffix_products.last * num)
    else
      suffix_products.append(num)
    end
  end

  suffix_products
end

# Builds output
def output(prefix_products, suffix_products, nums)
  result = []

  nums.reverse.each_with_index do |_num, index|
    case index
    when 0
      result.append(suffix_products[index + 1])
    when nums.length - 1
      result.append(prefix_products[index - 1])
    else
      result.append(prefix_products[index - 1] * suffix_products[index + 1])
    end
  end

  result
end

# Generate result from the product of prefixes and suffixes
def products(nums)
  prefix_products = build_prefix_products(nums)
  suffix_products = build_suffix_products(nums)
  suffix_products = suffix_products.reverse

  output(prefix_products, suffix_products, nums)
end

puts(products([1, 2, 3]))
# => [6, 3, 2]
