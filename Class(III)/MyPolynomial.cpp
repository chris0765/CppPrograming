#include "MyPolynomial.h"

myPolynomial::myPolynomial(int c, unsigned e){
    numTerms = 1;
    degree = e;
    terms = new myTerm[1];
    terms[0] = myTerm(c, e);
}
myPolynomial::myPolynomial(int nTerms, int mono[]){
    numTerms = nTerms;
    terms = new myTerm[nTerms];
    int cnt = 0;
    for(int i=0; i<nTerms; i++){
        myTerm tmp = myTerm(mono[i*2], (unsigned)mono[i*2+1]);
        int j=0;
        for(j=0; j<cnt; j++){
            if(terms[j]<tmp){
                for(int k=cnt; k>j; k--){
                    terms[k] = terms[k-1];
                }
                terms[j] = tmp;
                cnt++;
                break;
            }
        }
        if(j == cnt){
            terms[cnt++] = tmp;
        }
    }
    degree = terms[cnt-1].exp;
}
myPolynomial::myPolynomial(const myPolynomial& poly){
    numTerms = poly.numTerms;
    degree = poly.degree;
    terms = new myTerm[numTerms];
    for(int i=0; i<numTerms; i++)
        terms[i] = poly.terms[i];
}
int myPolynomial::getDegree() const{
    return degree;
}
unsigned myPolynomial::getNumTerms() const{
    return numTerms;
}
myPolynomial myPolynomial::ddx() const{
    int newNumTerms = numTerms;
    if(terms[0].exp == 0)
        newNumTerms--;
    int mono[newNumTerms*2];
    for(int i=numTerms-newNumTerms; i<numTerms; i++){
        myTerm tmp = terms[i].ddx();
        mono[(i-(numTerms-newNumTerms))*2] = tmp.coeff;
        mono[(i-(numTerms-newNumTerms))*2+1] = tmp.exp;
    }
    if(newNumTerms == 0){
        return myPolynomial(0, (unsigned)0);
    }
    return myPolynomial(newNumTerms, mono);
}
myPolynomial myPolynomial::operator +(const myPolynomial& poly) const{
    int newNumTerms = 0;
    myTerm tmp[numTerms+poly.numTerms];
    int a=0, b=0;
    while(a<numTerms||b<poly.numTerms){
        if(a==numTerms||(b<poly.numTerms && terms[a]<poly.terms[b])){
            if(poly.terms[b].coeff == 0){
                b++;
                continue;
            }
            tmp[newNumTerms++] = poly.terms[b++];
        }
        else if(b==poly.numTerms||(a<numTerms && poly.terms[b]<terms[a])){
            if(terms[a].coeff == 0){
                a++;
                continue;
            }
            tmp[newNumTerms++] = terms[a++];
        }
        else if(a<numTerms&&b<poly.numTerms&&terms[a].exp==poly.terms[b].exp){
            if(terms[a].coeff+poly.terms[b].coeff==0)
            {
                a++;b++;
                continue;
            }
            tmp[newNumTerms++] = myTerm(terms[a].coeff + poly.terms[b].coeff, terms[a].exp);
            a++;b++;
        }
    }
    int mono[(newNumTerms)*2];
    for(int i=0; i<newNumTerms; i++){
        mono[i*2] = tmp[i].coeff;
        mono[i*2+1] = tmp[i].exp;
    }
    if(newNumTerms == 0){
        return myPolynomial(0, (unsigned)0);
    }
    return myPolynomial(newNumTerms, mono);
}
myPolynomial myPolynomial::operator -(const myPolynomial& poly) const{
    int newNumTerms = 0;
    myTerm tmp[numTerms+poly.numTerms];
    int a=0, b=0;
    while(a<numTerms||b<poly.numTerms){
        if(a==numTerms||(b<poly.numTerms && terms[a]<poly.terms[b])){
            if(poly.terms[b].coeff == 0){
                b++;
                continue;
            }
            tmp[newNumTerms++] = -poly.terms[b++];
        }
        else if(b==poly.numTerms||(a<numTerms && poly.terms[b]<terms[a])){
            if(terms[a].coeff == 0){
                a++;
                continue;
            }
            tmp[newNumTerms++] = terms[a++];
        }
        else if(a<numTerms&&b<poly.numTerms&&terms[a].exp == poly.terms[b].exp){
            if(terms[a].coeff-poly.terms[b].coeff==0)
            {
                a++;b++;
                continue;
            }
            tmp[newNumTerms++] = myTerm(terms[a].coeff - poly.terms[b].coeff, terms[a].exp);
            a++;b++;
        }
    }
    int mono[(newNumTerms)*2];
    for(int i=0; i<newNumTerms; i++){
        mono[i*2] = tmp[i].coeff;
        mono[i*2+1] = tmp[i].exp;
    }
    if(newNumTerms == 0){
        return myPolynomial(0, (unsigned)0);
    }
    return myPolynomial(newNumTerms, mono);
}
myPolynomial myPolynomial::operator *(const myPolynomial& poly) const{
    int newNumTerms = 0;
    myTerm tmp[numTerms*poly.numTerms];
    for(int i=0; i<numTerms; i++){
        for(int j=0; j<poly.numTerms; j++){
            myTerm k = myTerm(terms[i].coeff * poly.terms[j].coeff, terms[i].exp + poly.terms[j].exp);
            if(k.coeff == 0)
                continue;
            int l=0;
            for(l=0; l<newNumTerms; l++){
                if(tmp[l]<k){
                    for(int t=newNumTerms; t>l; t--){
                        tmp[t] = tmp[t-1];
                    }
                    tmp[l] = k;
                    newNumTerms++;
                    break;
                }
                else if(tmp[l].exp==k.exp){
                    tmp[l].coeff += k.coeff;
                    break;
                }
            }
            if(l==newNumTerms){
                tmp[newNumTerms++] = k;
            }
        }
    }
    if(newNumTerms == 0){
        return myPolynomial(0, (unsigned)0);
    }
    int mono[(newNumTerms)*2];
    for(int i=0; i<newNumTerms; i++){
        mono[i*2] = tmp[i].coeff;
        mono[i*2+1] = tmp[i].exp;
    }
    return myPolynomial(newNumTerms, mono);
}
myPolynomial myPolynomial::operator *(int k) const{
    if(k==0){
        return myPolynomial(0, (unsigned)0);
    }
    int mono[numTerms*2];
    int newNumTerms = 0;
    for(int i=0; i<numTerms; i++){
        if(k * terms[i].coeff == 0)
            continue;
        mono[newNumTerms*2] = k * terms[i].coeff;
        mono[newNumTerms*2+1] = terms[i].exp;
        newNumTerms++;
    }
    if(newNumTerms == 0){
        return myPolynomial(0, (unsigned)0);
    }
    return myPolynomial(newNumTerms, mono);
}
myPolynomial operator *(int k, const myPolynomial& poly){
    return myPolynomial(poly * k);
}
long myPolynomial::operator ()(int x) const{
    long result = 0;
    for(int i=0; i<numTerms; i++){
        long tmp = 1;
        for(int j=0; j<terms[i].exp; j++)
            tmp *= x;
        result += (terms[i].coeff * tmp);
    }
    return result;
}
myPolynomial myPolynomial::operator -() const{
    return myPolynomial((*this) * (-1));
}
bool myPolynomial::operator ==(const myPolynomial& poly) const{
    if(numTerms != poly.numTerms)
        return false;
    for(int i=0; i<numTerms; i++)
        if(terms[i].coeff != poly.terms[i].coeff || terms[i].exp != poly.terms[i].exp)
            return false;
    return true;
}
bool myPolynomial::operator !=(const myPolynomial& poly) const{
    return !((*this)==poly);
}
myPolynomial& myPolynomial::operator =(const myPolynomial& poly){
    numTerms = poly.numTerms;
    degree = poly.degree;
    terms = new myTerm[numTerms];
    for(int i=0; i<numTerms; i++){
        terms[i] = poly.terms[i];
    }
    return *this;
}
myPolynomial& myPolynomial::operator +=(const myPolynomial& poly){
    (*this) = (*this) + poly;
    return *this;
}
myPolynomial& myPolynomial::operator -=(const myPolynomial& poly){
    (*this) = (*this) - poly;
    return *this;
}
myPolynomial& myPolynomial::operator *=(const myPolynomial& poly){
    (*this) = (*this) * poly;
    return *this;
}
myPolynomial& myPolynomial::operator *=(int k){
    (*this) = (*this) * k;
    return *this;
}

ostream& operator <<(ostream& outStream, const myPolynomial& poly){
    if(poly == myPolynomial::ZERO)
        return outStream<<0;
    for(int i=poly.numTerms-1; i>=0; i--){
        if(i!=poly.numTerms-1 && poly.terms[i].getCoeff()>0)
            outStream<<"+";
        outStream<<poly.terms[i];
    }
    return outStream;
}
const myPolynomial myPolynomial::ZERO(0);
const myPolynomial myPolynomial::ONE(1, (unsigned)0);
const myPolynomial myPolynomial::X(1, 1);