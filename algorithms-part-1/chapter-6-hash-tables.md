# Chapter 6 - Hash Tables

Algorithms Week 6 -  Hash Tables


Hash tables allow access at constant time by converting the key into a **hash**, this is done in Java by the ``hashCode()`` method which is inherited by every class.

Calculating hash codes should ideally use every bit from the key. A standard method of computation is **Horners method** which iterates over each bit of the key and reduces them by multiplying them by 31, treating the key as a base 31 number.

```
// horners method

hashCode() {
    int hash = 0;
    for (int i = 0; i < length(); i++ {
        hash = s[i] + (31 * hash);
    }
    return hash;
}
```

Creating hashes of composite data types can be done by applying the Horner method to the types inner data structures.

```
hashCode() {
    int hash = 17;
    hash = 31*hash + this.name.hashCode();
    hash = 31*hash + this.created_at.hashCode();
    return hash;
}
```

As hashes cannot be guaranteed to be completely uniform, we must account for **collision handling**, when two keys reduce to the same hash with a certain function. 

This leads to some other considerations and problems.

#### The Birthday Problem:

How long do we expect to wait before the first collision?

#### The Coupon Collector:

How long until every slot has a been filled with a key?

#### Load Balancing:

After M keys, how many keys does the most loaded slot have?


There are two simple approaches to collision handling.

### Separate Chaining

This approach applies a linked list to 'slots', and when a hash collision is detected the keys simply append to the end. This is very efficient if M is several times greater than N.

### Linear Probing / Open Addressing

This technique involves using a contiguous array and simply checking for open slots in adjacent indicies. This is good for using memory efficiently but as the array reaches maximum capacity it can slow down greatly.

## Some other considerations:

### Efficient hashing

Long keys can be hashed using a fraction of the keys (every 8 chars in a long string). This can be effective but leads to problems with regular keys such as urls or emails.

### pile up attacks

Hashes can be abused if an attacker knows the hash function - **pile-up** attacks can degrade a system by using lots of keys which reduce to the same hash.

### one-way hashing

One way hashes such as **RSA** hashes are used for security and digital fingerprint technology, although are inefficient for symbol tables.

## Some Applications of Symbol Tables

### Indexing

File indexing is a simple application of symbol tables. In order to quickly search for locations (page numbers) of items (words), we can enter the items into a symbol table for quick retreival.

### Sparse Vectors

When doing some vector calculations such as dot products, it is necessary to perform operations across whole rows or columns of vectors. This has a complexity proportional to N where N is the size of the vector. In many cases, the vectors are **sparse**, meaning that they are mainly zero values and could be ignored. By representing sparse vectors as a symbol table of only non-zero values, we can ignore zero values in our calculations and therefore have an algorithmic complexity equal only to the number of non-zero values.

[Back to index.](./README.md)
