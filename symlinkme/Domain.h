
#ifndef BRIDGE_H
#define BRIDGE_H

#ifndef leanInferenceWildcard
#define leanInferenceWildcard "_"
#endif

#include <cstddef>  
#include "clang/AST/AST.h"
#include <vector>
#include <string>
#include <memory>
#include <typeinfo>

#include "AST.h"
#include "Coords.h"

//#include <g3log/g3log.hpp>


using namespace std;

/*
- Space
- Ident
- Expr
- Value
- Defn
*/

namespace domain{



class Space;
class DerivedSpace;
class MapSpace;
class Frame;
class StandardFrame;
class AliasedFrame;
class DerivedFrame;
class DomainObject;
class DomainContainer;
template<typename ValueType,int ValueCount>
class ValueObject;

class EuclideanGeometry;

class EuclideanGeometryFrame;

class EuclideanGeometryStandardFrame;

class EuclideanGeometryAliasedFrame;

class EuclideanGeometryDerivedFrame;

class MeasurementSystem;

class SIMeasurementSystem;

class ImperialMeasurementSystem;

class AxisOrientation;

class NWUOrientation;

class NEDOrientation;

class ENUOrientation;

template<typename ValueType,int ValueCount>
class EuclideanGeometryRotation;

template<typename ValueType,int ValueCount>
class EuclideanGeometryOrientation;

template<typename ValueType,int ValueCount>
class EuclideanGeometryTransform;

template<typename ValueType,int ValueCount>
class EuclideanGeometryCoordinatePoint;

template<typename ValueType,int ValueCount>
class EuclideanGeometryCoordinateVector;

template<typename ValueType,int ValueCount>
class EuclideanGeometryScalar;

template<typename ValueType,int ValueCount>
class EuclideanGeometryQuantity;

class ClassicalTime;

class ClassicalTimeFrame;

class ClassicalTimeStandardFrame;

class ClassicalTimeAliasedFrame;

class ClassicalTimeDerivedFrame;

class MeasurementSystem;

class SIMeasurementSystem;

class ImperialMeasurementSystem;

class AxisOrientation;

class NWUOrientation;

class NEDOrientation;

class ENUOrientation;

template<typename ValueType,int ValueCount>
class ClassicalTimeTransform;

template<typename ValueType,int ValueCount>
class ClassicalTimeCoordinatePoint;

template<typename ValueType,int ValueCount>
class ClassicalTimeCoordinateVector;

template<typename ValueType,int ValueCount>
class ClassicalTimeScalar;

template<typename ValueType,int ValueCount>
class ClassicalTimeQuantity;

class EuclideanGeometry3;

class EuclideanGeometry3Frame;

class EuclideanGeometry3StandardFrame;

class EuclideanGeometry3AliasedFrame;

class EuclideanGeometry3DerivedFrame;

class MeasurementSystem;

class SIMeasurementSystem;

class ImperialMeasurementSystem;

class AxisOrientation;

class NWUOrientation;

class NEDOrientation;

class ENUOrientation;

template<typename ValueType,int ValueCount>
class EuclideanGeometry3Rotation;

template<typename ValueType,int ValueCount>
class EuclideanGeometry3Orientation;

template<typename ValueType,int ValueCount>
class EuclideanGeometry3Transform;

template<typename ValueType,int ValueCount>
class EuclideanGeometry3CoordinatePoint;

template<typename ValueType,int ValueCount>
class EuclideanGeometry3CoordinateVector;

template<typename ValueType,int ValueCount>
class EuclideanGeometry3Scalar;

template<typename ValueType,int ValueCount>
class EuclideanGeometry3Quantity;

class ClassicalVelocity;

class ClassicalVelocityFrame;

class ClassicalVelocityStandardFrame;

class ClassicalVelocityAliasedFrame;

class ClassicalVelocityDerivedFrame;

class MeasurementSystem;

class SIMeasurementSystem;

class ImperialMeasurementSystem;

class AxisOrientation;

class NWUOrientation;

class NEDOrientation;

class ENUOrientation;

template<typename ValueType,int ValueCount>
class ClassicalVelocityCoordinateVector;

template<typename ValueType,int ValueCount>
class ClassicalVelocityScalar;

template<typename ValueType,int ValueCount>
class ClassicalVelocityQuantity;

class ClassicalHertz;

class ClassicalHertzFrame;

class ClassicalHertzStandardFrame;

class ClassicalHertzAliasedFrame;

class ClassicalHertzDerivedFrame;

class MeasurementSystem;

class SIMeasurementSystem;

class ImperialMeasurementSystem;

class AxisOrientation;

class NWUOrientation;

class NEDOrientation;

class ENUOrientation;

template<typename ValueType,int ValueCount>
class ClassicalHertzCoordinateVector;

template<typename ValueType,int ValueCount>
class ClassicalHertzScalar;

template<typename ValueType,int ValueCount>
class ClassicalHertzQuantity;

class ClassicalLuminousIntensity;

class ClassicalLuminousIntensityFrame;

class ClassicalLuminousIntensityStandardFrame;

class ClassicalLuminousIntensityAliasedFrame;

class ClassicalLuminousIntensityDerivedFrame;

class MeasurementSystem;

class SIMeasurementSystem;

class ImperialMeasurementSystem;

class AxisOrientation;

class NWUOrientation;

class NEDOrientation;

class ENUOrientation;

template<typename ValueType,int ValueCount>
class ClassicalLuminousIntensityCoordinateVector;

template<typename ValueType,int ValueCount>
class ClassicalLuminousIntensityScalar;

template<typename ValueType,int ValueCount>
class ClassicalLuminousIntensityQuantity;

            
// Definition for Domain class 

class Domain {
public:
// Space
	std::vector<Space*>& getSpaces();


    Space* getSpace(std::string key);

    DomainObject* mkDefaultDomainContainer();
    DomainObject* mkDefaultDomainContainer(std::initializer_list<DomainObject*> operands);
    DomainObject* mkDefaultDomainContainer(std::vector<DomainObject*> operands);
    //Frame* mkFrame(std::string name, Space* space, Frame* parent);
    //Frame<sp>* mkAliasedFrame(std::string name, Frame* aliased);

    //Frame<sp>* mkDerivedFrame(std::string name, Frame* parent);


    MapSpace* mkMapSpace(Space* space, Frame* dom, Frame* cod);


    SIMeasurementSystem* mkSIMeasurementSystem(string name);

    ImperialMeasurementSystem* mkImperialMeasurementSystem(string name);


    std::vector<MeasurementSystem*> measurementSystems;
    std::vector<MeasurementSystem*> getMeasurementSystems() const{return measurementSystems;};




    NWUOrientation* mkNWUOrientation(string name);


    ENUOrientation* mkENUOrientation(string name);


    NEDOrientation* mkNEDOrientation(string name);



    std::vector<AxisOrientation*> axisOrientations;
    std::vector<AxisOrientation*> getAxisOrientations() const {return axisOrientations;};


	EuclideanGeometry* mkEuclideanGeometry(std::string key ,std::string name_, int dimension_);
	std::vector<EuclideanGeometry*> &getEuclideanGeometrySpaces() { return EuclideanGeometry_vec; }

	EuclideanGeometryAliasedFrame* mkEuclideanGeometryAliasedFrame(std::string name, domain::EuclideanGeometry* space, domain::EuclideanGeometryFrame* aliased, domain::MeasurementSystem* ms, domain::AxisOrientation* ax);
	EuclideanGeometryDerivedFrame* mkEuclideanGeometryDerivedFrame(std::string name, domain::EuclideanGeometry* space, domain::EuclideanGeometryFrame* parent, domain::MeasurementSystem* ms, domain::AxisOrientation* ax);

template <class ValueType, int ValueCount>
EuclideanGeometryRotation<ValueType,ValueCount>* mkEuclideanGeometryRotation(EuclideanGeometry* sp, std::shared_ptr<ValueType> values[ValueCount]){
    EuclideanGeometryRotation<ValueType,ValueCount>* dom_ = new EuclideanGeometryRotation<ValueType,ValueCount>(sp, {});
    //dom_->setValues(values);
    //this->EuclideanGeometryRotation_vec.push_back(dom_);
    for(int i = 0; i < ValueCount;i++){
        dom_->setValue(values[i],i);
    }

    return dom_;
}
                

template <class ValueType, int ValueCount>
EuclideanGeometryRotation<ValueType,ValueCount>* mkEuclideanGeometryRotation(){
    EuclideanGeometryRotation<ValueType,ValueCount>* dom_ = new EuclideanGeometryRotation<ValueType,ValueCount>({});
    //this->EuclideanGeometryRotation_vec.push_back(dom_);
    /*int i = 0;
    for(auto val : values){
        dom_->setValue(values[i],i++);
    } */  
    return dom_;
}


template <class ValueType, int ValueCount>
EuclideanGeometryOrientation<ValueType,ValueCount>* mkEuclideanGeometryOrientation(EuclideanGeometry* sp, std::shared_ptr<ValueType> values[ValueCount]){
    EuclideanGeometryOrientation<ValueType,ValueCount>* dom_ = new EuclideanGeometryOrientation<ValueType,ValueCount>(sp, {});
    //dom_->setValues(values);
    //this->EuclideanGeometryOrientation_vec.push_back(dom_);
    for(int i = 0; i < ValueCount;i++){
        dom_->setValue(values[i],i);
    }

    return dom_;
}
                

template <class ValueType, int ValueCount>
EuclideanGeometryOrientation<ValueType,ValueCount>* mkEuclideanGeometryOrientation(){
    EuclideanGeometryOrientation<ValueType,ValueCount>* dom_ = new EuclideanGeometryOrientation<ValueType,ValueCount>({});
    //this->EuclideanGeometryOrientation_vec.push_back(dom_);
    /*int i = 0;
    for(auto val : values){
        dom_->setValue(values[i],i++);
    } */  
    return dom_;
}


template <class ValueType, int ValueCount>
                        EuclideanGeometryTransform<ValueType,ValueCount>* mkEuclideanGeometryTransform(EuclideanGeometry* sp,EuclideanGeometryFrame* from,EuclideanGeometryFrame* to/*,   std::shared_ptr<ValueType> values[ValueCount]*/){
    EuclideanGeometryTransform <ValueType,ValueCount>* dom_ = new EuclideanGeometryTransform <ValueType,ValueCount>(sp, from, to, {});
    //((ValueObject<ValueType,ValueCount>)(dom_))->setValues(values);
    //this->EuclideanGeometryTransform_vec.push_back(dom_);
    /*for(int i = 0; i < ValueCount;i++){
        dom_->setValue(values[i],i);
    }*/
    return dom_;
}
                

template <class ValueType, int ValueCount>
EuclideanGeometryTransform<ValueType,ValueCount>* mkEuclideanGeometryTransform(){
    EuclideanGeometryTransform<ValueType,ValueCount>* dom_ = new EuclideanGeometryTransform<ValueType,ValueCount>({});
    //this->EuclideanGeometryTransform_vec.push_back(dom_);
    /*int i = 0;
    for(auto val : values){
        dom_->setValue(values[i],i++);
    } */  
    return dom_;
}


template <class ValueType, int ValueCount>
EuclideanGeometryCoordinatePoint<ValueType,ValueCount>* mkEuclideanGeometryCoordinatePoint(EuclideanGeometry* sp, std::shared_ptr<ValueType> values[ValueCount]){
    EuclideanGeometryCoordinatePoint<ValueType,ValueCount>* dom_ = new EuclideanGeometryCoordinatePoint<ValueType,ValueCount>(sp, {});
    //dom_->setValues(values);
    //this->EuclideanGeometryCoordinatePoint_vec.push_back(dom_);
    for(int i = 0; i < ValueCount;i++){
        dom_->setValue(values[i],i);
    }

    return dom_;
}
                

template <class ValueType, int ValueCount>
EuclideanGeometryCoordinatePoint<ValueType,ValueCount>* mkEuclideanGeometryCoordinatePoint(){
    EuclideanGeometryCoordinatePoint<ValueType,ValueCount>* dom_ = new EuclideanGeometryCoordinatePoint<ValueType,ValueCount>({});
    //this->EuclideanGeometryCoordinatePoint_vec.push_back(dom_);
    /*int i = 0;
    for(auto val : values){
        dom_->setValue(values[i],i++);
    } */  
    return dom_;
}


template <class ValueType, int ValueCount>
EuclideanGeometryCoordinateVector<ValueType,ValueCount>* mkEuclideanGeometryCoordinateVector(EuclideanGeometry* sp, std::shared_ptr<ValueType> values[ValueCount]){
    EuclideanGeometryCoordinateVector<ValueType,ValueCount>* dom_ = new EuclideanGeometryCoordinateVector<ValueType,ValueCount>(sp, {});
    //dom_->setValues(values);
    //this->EuclideanGeometryCoordinateVector_vec.push_back(dom_);
    for(int i = 0; i < ValueCount;i++){
        dom_->setValue(values[i],i);
    }

    return dom_;
}
                

template <class ValueType, int ValueCount>
EuclideanGeometryCoordinateVector<ValueType,ValueCount>* mkEuclideanGeometryCoordinateVector(){
    EuclideanGeometryCoordinateVector<ValueType,ValueCount>* dom_ = new EuclideanGeometryCoordinateVector<ValueType,ValueCount>({});
    //this->EuclideanGeometryCoordinateVector_vec.push_back(dom_);
    /*int i = 0;
    for(auto val : values){
        dom_->setValue(values[i],i++);
    } */  
    return dom_;
}


template <class ValueType, int ValueCount>
EuclideanGeometryScalar<ValueType,ValueCount>* mkEuclideanGeometryScalar(EuclideanGeometry* sp, std::shared_ptr<ValueType> values[ValueCount]){
    EuclideanGeometryScalar<ValueType,ValueCount>* dom_ = new EuclideanGeometryScalar<ValueType,ValueCount>(sp, {});
    //dom_->setValues(values);
    //this->EuclideanGeometryScalar_vec.push_back(dom_);
    for(int i = 0; i < ValueCount;i++){
        dom_->setValue(values[i],i);
    }

    return dom_;
}
                

template <class ValueType, int ValueCount>
EuclideanGeometryScalar<ValueType,ValueCount>* mkEuclideanGeometryScalar(){
    EuclideanGeometryScalar<ValueType,ValueCount>* dom_ = new EuclideanGeometryScalar<ValueType,ValueCount>({});
    //this->EuclideanGeometryScalar_vec.push_back(dom_);
    /*int i = 0;
    for(auto val : values){
        dom_->setValue(values[i],i++);
    } */  
    return dom_;
}


template <class ValueType, int ValueCount>
EuclideanGeometryQuantity<ValueType,ValueCount>* mkEuclideanGeometryQuantity(EuclideanGeometry* sp, std::shared_ptr<ValueType> values[ValueCount]){
    EuclideanGeometryQuantity<ValueType,ValueCount>* dom_ = new EuclideanGeometryQuantity<ValueType,ValueCount>(sp, {});
    //dom_->setValues(values);
    //this->EuclideanGeometryQuantity_vec.push_back(dom_);
    for(int i = 0; i < ValueCount;i++){
        dom_->setValue(values[i],i);
    }

    return dom_;
}
                

template <class ValueType, int ValueCount>
EuclideanGeometryQuantity<ValueType,ValueCount>* mkEuclideanGeometryQuantity(){
    EuclideanGeometryQuantity<ValueType,ValueCount>* dom_ = new EuclideanGeometryQuantity<ValueType,ValueCount>({});
    //this->EuclideanGeometryQuantity_vec.push_back(dom_);
    /*int i = 0;
    for(auto val : values){
        dom_->setValue(values[i],i++);
    } */  
    return dom_;
}

	ClassicalTime* mkClassicalTime(std::string key ,std::string name_);
	std::vector<ClassicalTime*> &getClassicalTimeSpaces() { return ClassicalTime_vec; }

	ClassicalTimeAliasedFrame* mkClassicalTimeAliasedFrame(std::string name, domain::ClassicalTime* space, domain::ClassicalTimeFrame* aliased, domain::MeasurementSystem* ms, domain::AxisOrientation* ax);
	ClassicalTimeDerivedFrame* mkClassicalTimeDerivedFrame(std::string name, domain::ClassicalTime* space, domain::ClassicalTimeFrame* parent, domain::MeasurementSystem* ms, domain::AxisOrientation* ax);

template <class ValueType, int ValueCount>
                        ClassicalTimeTransform<ValueType,ValueCount>* mkClassicalTimeTransform(ClassicalTime* sp,ClassicalTimeFrame* from,ClassicalTimeFrame* to/*,   std::shared_ptr<ValueType> values[ValueCount]*/){
    ClassicalTimeTransform <ValueType,ValueCount>* dom_ = new ClassicalTimeTransform <ValueType,ValueCount>(sp, from, to, {});
    //((ValueObject<ValueType,ValueCount>)(dom_))->setValues(values);
    //this->ClassicalTimeTransform_vec.push_back(dom_);
    /*for(int i = 0; i < ValueCount;i++){
        dom_->setValue(values[i],i);
    }*/
    return dom_;
}
                

template <class ValueType, int ValueCount>
ClassicalTimeTransform<ValueType,ValueCount>* mkClassicalTimeTransform(){
    ClassicalTimeTransform<ValueType,ValueCount>* dom_ = new ClassicalTimeTransform<ValueType,ValueCount>({});
    //this->ClassicalTimeTransform_vec.push_back(dom_);
    /*int i = 0;
    for(auto val : values){
        dom_->setValue(values[i],i++);
    } */  
    return dom_;
}


template <class ValueType, int ValueCount>
ClassicalTimeCoordinatePoint<ValueType,ValueCount>* mkClassicalTimeCoordinatePoint(ClassicalTime* sp, std::shared_ptr<ValueType> values[ValueCount]){
    ClassicalTimeCoordinatePoint<ValueType,ValueCount>* dom_ = new ClassicalTimeCoordinatePoint<ValueType,ValueCount>(sp, {});
    //dom_->setValues(values);
    //this->ClassicalTimeCoordinatePoint_vec.push_back(dom_);
    for(int i = 0; i < ValueCount;i++){
        dom_->setValue(values[i],i);
    }

    return dom_;
}
                

template <class ValueType, int ValueCount>
ClassicalTimeCoordinatePoint<ValueType,ValueCount>* mkClassicalTimeCoordinatePoint(){
    ClassicalTimeCoordinatePoint<ValueType,ValueCount>* dom_ = new ClassicalTimeCoordinatePoint<ValueType,ValueCount>({});
    //this->ClassicalTimeCoordinatePoint_vec.push_back(dom_);
    /*int i = 0;
    for(auto val : values){
        dom_->setValue(values[i],i++);
    } */  
    return dom_;
}


template <class ValueType, int ValueCount>
ClassicalTimeCoordinateVector<ValueType,ValueCount>* mkClassicalTimeCoordinateVector(ClassicalTime* sp, std::shared_ptr<ValueType> values[ValueCount]){
    ClassicalTimeCoordinateVector<ValueType,ValueCount>* dom_ = new ClassicalTimeCoordinateVector<ValueType,ValueCount>(sp, {});
    //dom_->setValues(values);
    //this->ClassicalTimeCoordinateVector_vec.push_back(dom_);
    for(int i = 0; i < ValueCount;i++){
        dom_->setValue(values[i],i);
    }

    return dom_;
}
                

template <class ValueType, int ValueCount>
ClassicalTimeCoordinateVector<ValueType,ValueCount>* mkClassicalTimeCoordinateVector(){
    ClassicalTimeCoordinateVector<ValueType,ValueCount>* dom_ = new ClassicalTimeCoordinateVector<ValueType,ValueCount>({});
    //this->ClassicalTimeCoordinateVector_vec.push_back(dom_);
    /*int i = 0;
    for(auto val : values){
        dom_->setValue(values[i],i++);
    } */  
    return dom_;
}


template <class ValueType, int ValueCount>
ClassicalTimeScalar<ValueType,ValueCount>* mkClassicalTimeScalar(ClassicalTime* sp, std::shared_ptr<ValueType> values[ValueCount]){
    ClassicalTimeScalar<ValueType,ValueCount>* dom_ = new ClassicalTimeScalar<ValueType,ValueCount>(sp, {});
    //dom_->setValues(values);
    //this->ClassicalTimeScalar_vec.push_back(dom_);
    for(int i = 0; i < ValueCount;i++){
        dom_->setValue(values[i],i);
    }

    return dom_;
}
                

template <class ValueType, int ValueCount>
ClassicalTimeScalar<ValueType,ValueCount>* mkClassicalTimeScalar(){
    ClassicalTimeScalar<ValueType,ValueCount>* dom_ = new ClassicalTimeScalar<ValueType,ValueCount>({});
    //this->ClassicalTimeScalar_vec.push_back(dom_);
    /*int i = 0;
    for(auto val : values){
        dom_->setValue(values[i],i++);
    } */  
    return dom_;
}


template <class ValueType, int ValueCount>
ClassicalTimeQuantity<ValueType,ValueCount>* mkClassicalTimeQuantity(ClassicalTime* sp, std::shared_ptr<ValueType> values[ValueCount]){
    ClassicalTimeQuantity<ValueType,ValueCount>* dom_ = new ClassicalTimeQuantity<ValueType,ValueCount>(sp, {});
    //dom_->setValues(values);
    //this->ClassicalTimeQuantity_vec.push_back(dom_);
    for(int i = 0; i < ValueCount;i++){
        dom_->setValue(values[i],i);
    }

    return dom_;
}
                

template <class ValueType, int ValueCount>
ClassicalTimeQuantity<ValueType,ValueCount>* mkClassicalTimeQuantity(){
    ClassicalTimeQuantity<ValueType,ValueCount>* dom_ = new ClassicalTimeQuantity<ValueType,ValueCount>({});
    //this->ClassicalTimeQuantity_vec.push_back(dom_);
    /*int i = 0;
    for(auto val : values){
        dom_->setValue(values[i],i++);
    } */  
    return dom_;
}

	EuclideanGeometry3* mkEuclideanGeometry3(std::string key ,std::string name_);
	std::vector<EuclideanGeometry3*> &getEuclideanGeometry3Spaces() { return EuclideanGeometry3_vec; }

	EuclideanGeometry3AliasedFrame* mkEuclideanGeometry3AliasedFrame(std::string name, domain::EuclideanGeometry3* space, domain::EuclideanGeometry3Frame* aliased, domain::MeasurementSystem* ms, domain::AxisOrientation* ax);
	EuclideanGeometry3DerivedFrame* mkEuclideanGeometry3DerivedFrame(std::string name, domain::EuclideanGeometry3* space, domain::EuclideanGeometry3Frame* parent, domain::MeasurementSystem* ms, domain::AxisOrientation* ax);

template <class ValueType, int ValueCount>
EuclideanGeometry3Rotation<ValueType,ValueCount>* mkEuclideanGeometry3Rotation(EuclideanGeometry3* sp, std::shared_ptr<ValueType> values[ValueCount]){
    EuclideanGeometry3Rotation<ValueType,ValueCount>* dom_ = new EuclideanGeometry3Rotation<ValueType,ValueCount>(sp, {});
    //dom_->setValues(values);
    //this->EuclideanGeometry3Rotation_vec.push_back(dom_);
    for(int i = 0; i < ValueCount;i++){
        dom_->setValue(values[i],i);
    }

    return dom_;
}
                

template <class ValueType, int ValueCount>
EuclideanGeometry3Rotation<ValueType,ValueCount>* mkEuclideanGeometry3Rotation(){
    EuclideanGeometry3Rotation<ValueType,ValueCount>* dom_ = new EuclideanGeometry3Rotation<ValueType,ValueCount>({});
    //this->EuclideanGeometry3Rotation_vec.push_back(dom_);
    /*int i = 0;
    for(auto val : values){
        dom_->setValue(values[i],i++);
    } */  
    return dom_;
}


template <class ValueType, int ValueCount>
EuclideanGeometry3Orientation<ValueType,ValueCount>* mkEuclideanGeometry3Orientation(EuclideanGeometry3* sp, std::shared_ptr<ValueType> values[ValueCount]){
    EuclideanGeometry3Orientation<ValueType,ValueCount>* dom_ = new EuclideanGeometry3Orientation<ValueType,ValueCount>(sp, {});
    //dom_->setValues(values);
    //this->EuclideanGeometry3Orientation_vec.push_back(dom_);
    for(int i = 0; i < ValueCount;i++){
        dom_->setValue(values[i],i);
    }

    return dom_;
}
                

template <class ValueType, int ValueCount>
EuclideanGeometry3Orientation<ValueType,ValueCount>* mkEuclideanGeometry3Orientation(){
    EuclideanGeometry3Orientation<ValueType,ValueCount>* dom_ = new EuclideanGeometry3Orientation<ValueType,ValueCount>({});
    //this->EuclideanGeometry3Orientation_vec.push_back(dom_);
    /*int i = 0;
    for(auto val : values){
        dom_->setValue(values[i],i++);
    } */  
    return dom_;
}


template <class ValueType, int ValueCount>
                        EuclideanGeometry3Transform<ValueType,ValueCount>* mkEuclideanGeometry3Transform(EuclideanGeometry3* sp,EuclideanGeometry3Frame* from,EuclideanGeometry3Frame* to/*,   std::shared_ptr<ValueType> values[ValueCount]*/){
    EuclideanGeometry3Transform <ValueType,ValueCount>* dom_ = new EuclideanGeometry3Transform <ValueType,ValueCount>(sp, from, to, {});
    //((ValueObject<ValueType,ValueCount>)(dom_))->setValues(values);
    //this->EuclideanGeometry3Transform_vec.push_back(dom_);
    /*for(int i = 0; i < ValueCount;i++){
        dom_->setValue(values[i],i);
    }*/
    return dom_;
}
                

template <class ValueType, int ValueCount>
EuclideanGeometry3Transform<ValueType,ValueCount>* mkEuclideanGeometry3Transform(){
    EuclideanGeometry3Transform<ValueType,ValueCount>* dom_ = new EuclideanGeometry3Transform<ValueType,ValueCount>({});
    //this->EuclideanGeometry3Transform_vec.push_back(dom_);
    /*int i = 0;
    for(auto val : values){
        dom_->setValue(values[i],i++);
    } */  
    return dom_;
}


template <class ValueType, int ValueCount>
EuclideanGeometry3CoordinatePoint<ValueType,ValueCount>* mkEuclideanGeometry3CoordinatePoint(EuclideanGeometry3* sp, std::shared_ptr<ValueType> values[ValueCount]){
    EuclideanGeometry3CoordinatePoint<ValueType,ValueCount>* dom_ = new EuclideanGeometry3CoordinatePoint<ValueType,ValueCount>(sp, {});
    //dom_->setValues(values);
    //this->EuclideanGeometry3CoordinatePoint_vec.push_back(dom_);
    for(int i = 0; i < ValueCount;i++){
        dom_->setValue(values[i],i);
    }

    return dom_;
}
                

template <class ValueType, int ValueCount>
EuclideanGeometry3CoordinatePoint<ValueType,ValueCount>* mkEuclideanGeometry3CoordinatePoint(){
    EuclideanGeometry3CoordinatePoint<ValueType,ValueCount>* dom_ = new EuclideanGeometry3CoordinatePoint<ValueType,ValueCount>({});
    //this->EuclideanGeometry3CoordinatePoint_vec.push_back(dom_);
    /*int i = 0;
    for(auto val : values){
        dom_->setValue(values[i],i++);
    } */  
    return dom_;
}


template <class ValueType, int ValueCount>
EuclideanGeometry3CoordinateVector<ValueType,ValueCount>* mkEuclideanGeometry3CoordinateVector(EuclideanGeometry3* sp, std::shared_ptr<ValueType> values[ValueCount]){
    EuclideanGeometry3CoordinateVector<ValueType,ValueCount>* dom_ = new EuclideanGeometry3CoordinateVector<ValueType,ValueCount>(sp, {});
    //dom_->setValues(values);
    //this->EuclideanGeometry3CoordinateVector_vec.push_back(dom_);
    for(int i = 0; i < ValueCount;i++){
        dom_->setValue(values[i],i);
    }

    return dom_;
}
                

template <class ValueType, int ValueCount>
EuclideanGeometry3CoordinateVector<ValueType,ValueCount>* mkEuclideanGeometry3CoordinateVector(){
    EuclideanGeometry3CoordinateVector<ValueType,ValueCount>* dom_ = new EuclideanGeometry3CoordinateVector<ValueType,ValueCount>({});
    //this->EuclideanGeometry3CoordinateVector_vec.push_back(dom_);
    /*int i = 0;
    for(auto val : values){
        dom_->setValue(values[i],i++);
    } */  
    return dom_;
}


template <class ValueType, int ValueCount>
EuclideanGeometry3Scalar<ValueType,ValueCount>* mkEuclideanGeometry3Scalar(EuclideanGeometry3* sp, std::shared_ptr<ValueType> values[ValueCount]){
    EuclideanGeometry3Scalar<ValueType,ValueCount>* dom_ = new EuclideanGeometry3Scalar<ValueType,ValueCount>(sp, {});
    //dom_->setValues(values);
    //this->EuclideanGeometry3Scalar_vec.push_back(dom_);
    for(int i = 0; i < ValueCount;i++){
        dom_->setValue(values[i],i);
    }

    return dom_;
}
                

template <class ValueType, int ValueCount>
EuclideanGeometry3Scalar<ValueType,ValueCount>* mkEuclideanGeometry3Scalar(){
    EuclideanGeometry3Scalar<ValueType,ValueCount>* dom_ = new EuclideanGeometry3Scalar<ValueType,ValueCount>({});
    //this->EuclideanGeometry3Scalar_vec.push_back(dom_);
    /*int i = 0;
    for(auto val : values){
        dom_->setValue(values[i],i++);
    } */  
    return dom_;
}


template <class ValueType, int ValueCount>
EuclideanGeometry3Quantity<ValueType,ValueCount>* mkEuclideanGeometry3Quantity(EuclideanGeometry3* sp, std::shared_ptr<ValueType> values[ValueCount]){
    EuclideanGeometry3Quantity<ValueType,ValueCount>* dom_ = new EuclideanGeometry3Quantity<ValueType,ValueCount>(sp, {});
    //dom_->setValues(values);
    //this->EuclideanGeometry3Quantity_vec.push_back(dom_);
    for(int i = 0; i < ValueCount;i++){
        dom_->setValue(values[i],i);
    }

    return dom_;
}
                

template <class ValueType, int ValueCount>
EuclideanGeometry3Quantity<ValueType,ValueCount>* mkEuclideanGeometry3Quantity(){
    EuclideanGeometry3Quantity<ValueType,ValueCount>* dom_ = new EuclideanGeometry3Quantity<ValueType,ValueCount>({});
    //this->EuclideanGeometry3Quantity_vec.push_back(dom_);
    /*int i = 0;
    for(auto val : values){
        dom_->setValue(values[i],i++);
    } */  
    return dom_;
}

	ClassicalVelocity* mkClassicalVelocity(std::string key, std::string name_,Space* base1, Space* base2);
	std::vector<ClassicalVelocity*> &getClassicalVelocitySpaces() { return ClassicalVelocity_vec; }

	ClassicalVelocityAliasedFrame* mkClassicalVelocityAliasedFrame(std::string name, domain::ClassicalVelocity* space, domain::ClassicalVelocityFrame* aliased, domain::MeasurementSystem* ms, domain::AxisOrientation* ax);
	ClassicalVelocityDerivedFrame* mkClassicalVelocityDerivedFrame(std::string name, domain::ClassicalVelocity* space, domain::ClassicalVelocityFrame* parent, domain::MeasurementSystem* ms, domain::AxisOrientation* ax);

template <class ValueType, int ValueCount>
ClassicalVelocityCoordinateVector<ValueType,ValueCount>* mkClassicalVelocityCoordinateVector(ClassicalVelocity* sp, std::shared_ptr<ValueType> values[ValueCount]){
    ClassicalVelocityCoordinateVector<ValueType,ValueCount>* dom_ = new ClassicalVelocityCoordinateVector<ValueType,ValueCount>(sp, {});
    //dom_->setValues(values);
    //this->ClassicalVelocityCoordinateVector_vec.push_back(dom_);
    for(int i = 0; i < ValueCount;i++){
        dom_->setValue(values[i],i);
    }

    return dom_;
}
                

template <class ValueType, int ValueCount>
ClassicalVelocityCoordinateVector<ValueType,ValueCount>* mkClassicalVelocityCoordinateVector(){
    ClassicalVelocityCoordinateVector<ValueType,ValueCount>* dom_ = new ClassicalVelocityCoordinateVector<ValueType,ValueCount>({});
    //this->ClassicalVelocityCoordinateVector_vec.push_back(dom_);
    /*int i = 0;
    for(auto val : values){
        dom_->setValue(values[i],i++);
    } */  
    return dom_;
}


template <class ValueType, int ValueCount>
ClassicalVelocityScalar<ValueType,ValueCount>* mkClassicalVelocityScalar(ClassicalVelocity* sp, std::shared_ptr<ValueType> values[ValueCount]){
    ClassicalVelocityScalar<ValueType,ValueCount>* dom_ = new ClassicalVelocityScalar<ValueType,ValueCount>(sp, {});
    //dom_->setValues(values);
    //this->ClassicalVelocityScalar_vec.push_back(dom_);
    for(int i = 0; i < ValueCount;i++){
        dom_->setValue(values[i],i);
    }

    return dom_;
}
                

template <class ValueType, int ValueCount>
ClassicalVelocityScalar<ValueType,ValueCount>* mkClassicalVelocityScalar(){
    ClassicalVelocityScalar<ValueType,ValueCount>* dom_ = new ClassicalVelocityScalar<ValueType,ValueCount>({});
    //this->ClassicalVelocityScalar_vec.push_back(dom_);
    /*int i = 0;
    for(auto val : values){
        dom_->setValue(values[i],i++);
    } */  
    return dom_;
}


template <class ValueType, int ValueCount>
ClassicalVelocityQuantity<ValueType,ValueCount>* mkClassicalVelocityQuantity(ClassicalVelocity* sp, std::shared_ptr<ValueType> values[ValueCount]){
    ClassicalVelocityQuantity<ValueType,ValueCount>* dom_ = new ClassicalVelocityQuantity<ValueType,ValueCount>(sp, {});
    //dom_->setValues(values);
    //this->ClassicalVelocityQuantity_vec.push_back(dom_);
    for(int i = 0; i < ValueCount;i++){
        dom_->setValue(values[i],i);
    }

    return dom_;
}
                

template <class ValueType, int ValueCount>
ClassicalVelocityQuantity<ValueType,ValueCount>* mkClassicalVelocityQuantity(){
    ClassicalVelocityQuantity<ValueType,ValueCount>* dom_ = new ClassicalVelocityQuantity<ValueType,ValueCount>({});
    //this->ClassicalVelocityQuantity_vec.push_back(dom_);
    /*int i = 0;
    for(auto val : values){
        dom_->setValue(values[i],i++);
    } */  
    return dom_;
}

	ClassicalHertz* mkClassicalHertz(std::string key ,std::string name_);
	std::vector<ClassicalHertz*> &getClassicalHertzSpaces() { return ClassicalHertz_vec; }

	ClassicalHertzAliasedFrame* mkClassicalHertzAliasedFrame(std::string name, domain::ClassicalHertz* space, domain::ClassicalHertzFrame* aliased, domain::MeasurementSystem* ms, domain::AxisOrientation* ax);
	ClassicalHertzDerivedFrame* mkClassicalHertzDerivedFrame(std::string name, domain::ClassicalHertz* space, domain::ClassicalHertzFrame* parent, domain::MeasurementSystem* ms, domain::AxisOrientation* ax);

template <class ValueType, int ValueCount>
ClassicalHertzCoordinateVector<ValueType,ValueCount>* mkClassicalHertzCoordinateVector(ClassicalHertz* sp, std::shared_ptr<ValueType> values[ValueCount]){
    ClassicalHertzCoordinateVector<ValueType,ValueCount>* dom_ = new ClassicalHertzCoordinateVector<ValueType,ValueCount>(sp, {});
    //dom_->setValues(values);
    //this->ClassicalHertzCoordinateVector_vec.push_back(dom_);
    for(int i = 0; i < ValueCount;i++){
        dom_->setValue(values[i],i);
    }

    return dom_;
}
                

template <class ValueType, int ValueCount>
ClassicalHertzCoordinateVector<ValueType,ValueCount>* mkClassicalHertzCoordinateVector(){
    ClassicalHertzCoordinateVector<ValueType,ValueCount>* dom_ = new ClassicalHertzCoordinateVector<ValueType,ValueCount>({});
    //this->ClassicalHertzCoordinateVector_vec.push_back(dom_);
    /*int i = 0;
    for(auto val : values){
        dom_->setValue(values[i],i++);
    } */  
    return dom_;
}


template <class ValueType, int ValueCount>
ClassicalHertzScalar<ValueType,ValueCount>* mkClassicalHertzScalar(ClassicalHertz* sp, std::shared_ptr<ValueType> values[ValueCount]){
    ClassicalHertzScalar<ValueType,ValueCount>* dom_ = new ClassicalHertzScalar<ValueType,ValueCount>(sp, {});
    //dom_->setValues(values);
    //this->ClassicalHertzScalar_vec.push_back(dom_);
    for(int i = 0; i < ValueCount;i++){
        dom_->setValue(values[i],i);
    }

    return dom_;
}
                

template <class ValueType, int ValueCount>
ClassicalHertzScalar<ValueType,ValueCount>* mkClassicalHertzScalar(){
    ClassicalHertzScalar<ValueType,ValueCount>* dom_ = new ClassicalHertzScalar<ValueType,ValueCount>({});
    //this->ClassicalHertzScalar_vec.push_back(dom_);
    /*int i = 0;
    for(auto val : values){
        dom_->setValue(values[i],i++);
    } */  
    return dom_;
}


template <class ValueType, int ValueCount>
ClassicalHertzQuantity<ValueType,ValueCount>* mkClassicalHertzQuantity(ClassicalHertz* sp, std::shared_ptr<ValueType> values[ValueCount]){
    ClassicalHertzQuantity<ValueType,ValueCount>* dom_ = new ClassicalHertzQuantity<ValueType,ValueCount>(sp, {});
    //dom_->setValues(values);
    //this->ClassicalHertzQuantity_vec.push_back(dom_);
    for(int i = 0; i < ValueCount;i++){
        dom_->setValue(values[i],i);
    }

    return dom_;
}
                

template <class ValueType, int ValueCount>
ClassicalHertzQuantity<ValueType,ValueCount>* mkClassicalHertzQuantity(){
    ClassicalHertzQuantity<ValueType,ValueCount>* dom_ = new ClassicalHertzQuantity<ValueType,ValueCount>({});
    //this->ClassicalHertzQuantity_vec.push_back(dom_);
    /*int i = 0;
    for(auto val : values){
        dom_->setValue(values[i],i++);
    } */  
    return dom_;
}

	ClassicalLuminousIntensity* mkClassicalLuminousIntensity(std::string key ,std::string name_);
	std::vector<ClassicalLuminousIntensity*> &getClassicalLuminousIntensitySpaces() { return ClassicalLuminousIntensity_vec; }

	ClassicalLuminousIntensityAliasedFrame* mkClassicalLuminousIntensityAliasedFrame(std::string name, domain::ClassicalLuminousIntensity* space, domain::ClassicalLuminousIntensityFrame* aliased, domain::MeasurementSystem* ms, domain::AxisOrientation* ax);
	ClassicalLuminousIntensityDerivedFrame* mkClassicalLuminousIntensityDerivedFrame(std::string name, domain::ClassicalLuminousIntensity* space, domain::ClassicalLuminousIntensityFrame* parent, domain::MeasurementSystem* ms, domain::AxisOrientation* ax);

template <class ValueType, int ValueCount>
ClassicalLuminousIntensityCoordinateVector<ValueType,ValueCount>* mkClassicalLuminousIntensityCoordinateVector(ClassicalLuminousIntensity* sp, std::shared_ptr<ValueType> values[ValueCount]){
    ClassicalLuminousIntensityCoordinateVector<ValueType,ValueCount>* dom_ = new ClassicalLuminousIntensityCoordinateVector<ValueType,ValueCount>(sp, {});
    //dom_->setValues(values);
    //this->ClassicalLuminousIntensityCoordinateVector_vec.push_back(dom_);
    for(int i = 0; i < ValueCount;i++){
        dom_->setValue(values[i],i);
    }

    return dom_;
}
                

template <class ValueType, int ValueCount>
ClassicalLuminousIntensityCoordinateVector<ValueType,ValueCount>* mkClassicalLuminousIntensityCoordinateVector(){
    ClassicalLuminousIntensityCoordinateVector<ValueType,ValueCount>* dom_ = new ClassicalLuminousIntensityCoordinateVector<ValueType,ValueCount>({});
    //this->ClassicalLuminousIntensityCoordinateVector_vec.push_back(dom_);
    /*int i = 0;
    for(auto val : values){
        dom_->setValue(values[i],i++);
    } */  
    return dom_;
}


template <class ValueType, int ValueCount>
ClassicalLuminousIntensityScalar<ValueType,ValueCount>* mkClassicalLuminousIntensityScalar(ClassicalLuminousIntensity* sp, std::shared_ptr<ValueType> values[ValueCount]){
    ClassicalLuminousIntensityScalar<ValueType,ValueCount>* dom_ = new ClassicalLuminousIntensityScalar<ValueType,ValueCount>(sp, {});
    //dom_->setValues(values);
    //this->ClassicalLuminousIntensityScalar_vec.push_back(dom_);
    for(int i = 0; i < ValueCount;i++){
        dom_->setValue(values[i],i);
    }

    return dom_;
}
                

template <class ValueType, int ValueCount>
ClassicalLuminousIntensityScalar<ValueType,ValueCount>* mkClassicalLuminousIntensityScalar(){
    ClassicalLuminousIntensityScalar<ValueType,ValueCount>* dom_ = new ClassicalLuminousIntensityScalar<ValueType,ValueCount>({});
    //this->ClassicalLuminousIntensityScalar_vec.push_back(dom_);
    /*int i = 0;
    for(auto val : values){
        dom_->setValue(values[i],i++);
    } */  
    return dom_;
}


template <class ValueType, int ValueCount>
ClassicalLuminousIntensityQuantity<ValueType,ValueCount>* mkClassicalLuminousIntensityQuantity(ClassicalLuminousIntensity* sp, std::shared_ptr<ValueType> values[ValueCount]){
    ClassicalLuminousIntensityQuantity<ValueType,ValueCount>* dom_ = new ClassicalLuminousIntensityQuantity<ValueType,ValueCount>(sp, {});
    //dom_->setValues(values);
    //this->ClassicalLuminousIntensityQuantity_vec.push_back(dom_);
    for(int i = 0; i < ValueCount;i++){
        dom_->setValue(values[i],i);
    }

    return dom_;
}
                

template <class ValueType, int ValueCount>
ClassicalLuminousIntensityQuantity<ValueType,ValueCount>* mkClassicalLuminousIntensityQuantity(){
    ClassicalLuminousIntensityQuantity<ValueType,ValueCount>* dom_ = new ClassicalLuminousIntensityQuantity<ValueType,ValueCount>({});
    //this->ClassicalLuminousIntensityQuantity_vec.push_back(dom_);
    /*int i = 0;
    for(auto val : values){
        dom_->setValue(values[i],i++);
    } */  
    return dom_;
}

private:

	std::unordered_map<std::string, Space*> Space_map;
	std::vector<Space*> Space_vec;
	std::vector<EuclideanGeometry*> EuclideanGeometry_vec;
	std::vector<ClassicalTime*> ClassicalTime_vec;
	std::vector<EuclideanGeometry3*> EuclideanGeometry3_vec;
	std::vector<ClassicalVelocity*> ClassicalVelocity_vec;
	std::vector<ClassicalHertz*> ClassicalHertz_vec;
	std::vector<ClassicalLuminousIntensity*> ClassicalLuminousIntensity_vec;
};


class Space {
public:
	Space() {};
    Space(string name, int dimension) : name_(name), dimension_(dimension) {};
    virtual ~Space(){};
	virtual std::string toString() const {
		return "Not implemented"; 
	}
    virtual std::string getName() const {
        return this->name_;
    }
    int getDimension() const {
        return this->dimension_;
    }

    std::vector<Frame*> getFrames() const { return this->frames_; };
    void addFrame(Frame* frame);

protected:
    std::vector<Frame*> frames_;
    std::string name_;
    int dimension_;

};

class MeasurementSystem {
public :
    MeasurementSystem(std::string name) : name_(name) {};
    virtual ~MeasurementSystem() {};
    virtual std::string toString() = 0;

    virtual std::string getName() const { return this->name_; };

protected :
    std::string name_;
};

class SIMeasurementSystem : public MeasurementSystem {
public:
    SIMeasurementSystem(std::string name) : MeasurementSystem(name) {};
    //virtual ~SIMeasurementSystem() {};
    virtual std::string toString() override { return "@@SI " + this->name_; };
};

class ImperialMeasurementSystem : public MeasurementSystem {
public:
    ImperialMeasurementSystem(std::string name) : MeasurementSystem(name) {};
   // virtual ~SIMeasurementSystem() {};
    virtual std::string toString() override { return "@@Imperial " + this->name_; };
};

class AxisOrientation {
public:
    AxisOrientation(std::string name) : name_(name) {};
    virtual ~AxisOrientation() {};
    virtual std::string toString() = 0;

    virtual std::string getName() const { return this->name_; };

protected :
    std::string name_;
};

class NWUOrientation : public AxisOrientation {
public:
    NWUOrientation(std::string name) : AxisOrientation(name) {};
    //virtual ~NWUOrientation() {};
    virtual std::string toString() override { return "@@NWU " + this->name_; };
};

class NEDOrientation : public AxisOrientation {
public:
    NEDOrientation(std::string name) : AxisOrientation(name) {};
    //virtual ~NEDOrientation() {};
    virtual std::string toString() override { return "@@NED " + this->name_; };
};

class ENUOrientation : public AxisOrientation {
public:
    ENUOrientation(std::string name) : AxisOrientation(name) {};
    //virtual ~ENUOrientation() {};
    virtual std::string toString() override { return "@@ENU " + this->name_; };
};

class Frame {
public:
    Frame(std::string name, Space* sp) : name_(name), sp_(sp) {};
    Frame() {};
    virtual ~Frame(){};
    virtual std::string toString() const {
        return std::string("@@") + typeid(sp_).name() + "Frame " + this->getName();
    }

    //Frame* getParent() const{ return parent_; };
    //void setParent(Frame* parent);

    virtual std::string getName() const { return name_; };

    Space* getSpace() const { return sp_; };

protected:
    std::string name_;
    Space* sp_;
};

class StandardFrame : public Frame {
public:
    StandardFrame(Space* sp) : Frame("Standard", sp) {};
    StandardFrame() {};
    virtual ~StandardFrame(){};

    virtual std::string toString() const override { return this->getName() + "(" + this->sp_->getName() + ")"; };

    virtual std::string getName() const override { return this->sp_->getName() + ".standardFrame"; };

    //Space* getSpace() const { return space_; };

protected:
    std::string alias_;
};

class AliasedFrame : public Frame {
public:
    AliasedFrame(std::string name, Space* sp, Frame* original, domain::MeasurementSystem* ms, AxisOrientation* ax) : Frame(name, sp), original_(original), units_(ms), orient_(ax) {};
    AliasedFrame() {};
    virtual ~AliasedFrame(){};
    virtual std::string toString() const {
        return this->getName() + std::string("(") + this->sp_->getName() + "," + original_->getName() + ")";
    }

    Frame* getAliased() const{ return original_; };
    MeasurementSystem* getUnits() const { return units_; };
    AxisOrientation* getOrientation() const { return orient_; };
    void setAliased(Frame* original);

    std::string getName() const { return name_; };

    //Space* getSpace() const { return this->sp_; };

protected:
    Frame* original_;
    MeasurementSystem* units_;
    AxisOrientation* orient_;
    //std::string name_;
};

class DerivedFrame : public Frame {
public:
    DerivedFrame(std::string name, domain::Space* sp, Frame* parent, MeasurementSystem* ms, AxisOrientation* ax) : Frame(name, sp), parent_(parent), units_(ms), orient_(ax) {};
    DerivedFrame() {};
    virtual ~DerivedFrame(){};
    virtual std::string toString() const override {
        return this->getName() + std::string("(") + this->sp_->getName() + "," + parent_->getName() + ")";
    }

    Frame* getParent() const{ return parent_; };
    MeasurementSystem* getUnits() const { return units_; };
    AxisOrientation* getOrientation() const { return orient_; };
    void setParent(Frame* parent);

    //std::string getName() const { return name_; };
protected:
    Frame* parent_;
    MeasurementSystem* units_;
    AxisOrientation* orient_;
};

class DerivedSpace : public Space {
public:
    DerivedSpace() {};
    DerivedSpace(string name, Space* base1, Space* base2) :  Space(name, base1->getDimension()*base2->getDimension()), base_1(base1), base_2(base2) {
        
    }

    Space* getBase1() const {
        return this->base_1;
    }

    Space* getBase2() const {
        return this->base_2;
    }

    virtual ~DerivedSpace(){};
	virtual std::string toString() const override {
		return "Not implemented"; 
	}

protected:
    Space* base_1;
    Space* base_2;
};



//pretend this is a union
class MapSpace : public Space {
public:
	MapSpace() {}
	MapSpace(domain::Space* domain, domain::Space* codomain) : domain_(domain), codomain_(codomain), change_space_{true}, change_frame_{true} {};

    MapSpace(domain::Space* domain, domain::Space* codomain, Frame* domain_frame, Frame* codomain_frame) 
        : domain_(domain), domain_frame_(domain_frame), codomain_(codomain), codomain_frame_(codomain_frame), change_space_{true}, change_frame_{true} {};

    MapSpace(domain::Space* domain, Frame* domain_frame, Frame* codomain_frame)
        : domain_(domain), domain_frame_(domain_frame), codomain_(nullptr), codomain_frame_(codomain_frame), change_space_{false}, change_frame_{true} {};
	std::string toString() const {
        return "@@Map(" + this->getName() + ")";
    };
    std::string getName() const{
        if(change_space_){
            if(change_frame_){
                return domain_->getName()+"."+domain_frame_->getName()+"->"+codomain_->getName()+"."+codomain_frame_->getName();
            }
            else{
                return domain_->getName()+"->"+codomain_->getName();
            }
        }
        else{
            if(change_frame_){
                return domain_->getName()+"."+domain_frame_->getName()+"->"+domain_->getName()+"."+codomain_frame_->getName();
            }
        }
        return "";
    }
        

	domain::Space* domain_;
	domain::Frame* domain_frame_;

    domain::Space* codomain_;
    domain::Frame* codomain_frame_;
    
    bool change_space_;
    bool change_frame_;
};
class DomainObject {
public:
    DomainObject(std::initializer_list<DomainObject*> args);
    DomainObject(std::vector<DomainObject*> operands) : operands_(operands) {};
    DomainObject(){};
    virtual ~DomainObject(){};
    DomainObject* getOperand(int i);
    std::vector<DomainObject*> getOperands() const { return operands_; };
    void setOperands(std::vector<DomainObject*> operands);

    virtual std::string toString();
    friend class DomainObject; 
  
protected:
    std::vector<DomainObject*> operands_;
    int operand_count;
};

class DomainContainer : public DomainObject{
public:
        DomainContainer() : DomainObject(), inner_(nullptr) {};
        DomainContainer(DomainObject* inner) : inner_(inner) {};
        DomainContainer(std::initializer_list<DomainObject*> operands);
        DomainContainer(std::vector<DomainObject*> operands);
        virtual std::string toString() override;// { this->hasValue() ? this->inner_->toString() : "No Provided Interpretation"; }
        DomainObject* getValue() const { return this->inner_; }
        void setValue(DomainObject* obj);
        bool hasValue();
        

private:
    DomainObject* inner_;
};


template <typename ValueType, int ValueCount>
class ValueObject : public DomainObject {
public:
    // ValueCoords() : DomainObject() {};

    ValueObject() : DomainObject(){
        for(int i = 0; i<ValueCount;i++){
            this->values_[i] = nullptr;
        }
    };

    ValueObject(std::initializer_list<DomainObject*> args) :  DomainObject(args) {
        for(int i = 0; i<ValueCount;i++){
            this->values_[i] = nullptr;
        }

    }
    ValueObject(std::vector<DomainObject*> operands) : DomainObject(operands) {
        for(int i = 0; i<ValueCount;i++){
            this->values_[i] = nullptr;
        }

    }

    ~ValueObject() {
        //for(auto v : this->values_){
           // delete v;
        //}
    }

    ValueObject(ValueType* values...) : DomainObject() {
        int i = 0;
        for(auto val : {values}){
            if(i == ValueCount)
                throw "Out of Range";
            this->values_[i++] = std::make_shared<ValueType>(*val);

        }
    }

    ValueObject(std::initializer_list<DomainObject*> args, ValueType* values...) : ValueObject(values), DomainObject(args)
    {
    }

    ValueObject(std::vector<DomainObject*> operands, ValueType* values...) : ValueObject(values), DomainObject(operands)
    {
        int i = 0;
        for (auto val : { values}){
            if (i == ValueCount)
                throw "Out of Range";
            this->values_[i++] = std::make_shared<ValueType>(*val);

        }
    }

    virtual std::string toString() override {
        std::string ret = "Value=<";
    int i = 1;
        for(auto val : this->values_){
        ret += (val ? std::to_string(*val) : "UNK") + (i++ == ValueCount ? "" : ",");
    }
        return ret + ">";
    }

    ValueObject(ValueType* values[ValueCount]) : DomainObject(), values_(values) { };

    std::shared_ptr<ValueType> getValue(int index) const {
        if(index< 0 or index >= ValueCount)
            throw "Invalid Index";
        return this->values_[index];
    };

    void setValue(ValueType value, int index)
    {
        if (index < 0 or index >= ValueCount)
            throw "Invalid Index";
        if (this->values_[index])
            *this->values_[index] = value;
        else
            this->values_[index] = std::make_shared<ValueType>(value);
        //this->values_[index] = new ValueType(value)
    };

    void setValue(std::shared_ptr<ValueType> value, int index)
    {
        if (index < 0 or index >= ValueCount)
            throw "Invalid Index";
        if (this->values_[index])
            if(value)
                *this->values_[index] = *value;
            else{
                this->values_[index] = std::make_shared<ValueType>(*value);
            }
        else
            this->values_[index] = value ? std::make_shared<ValueType>(*value) : nullptr;
        //this->values_[index] = value ? new ValueType(*value) : nullptr;
    };
    protected:
    std::shared_ptr<ValueType> values_[ValueCount];
};



class EuclideanGeometry : public Space {
    public:
	    EuclideanGeometry(std::string name, int dimension) : Space(name, dimension) {};
	    std::string getName() const override { return name_; }; 
	    
        void addFrame(EuclideanGeometryFrame* frame);
	    std::string toString() const override {
		    return "@@EuclideanGeometry  " + getName()   + "("+ std::to_string(getDimension()) + ")"; 
	    }

    private:
    };


class EuclideanGeometryFrame : public Frame {
public:
	EuclideanGeometryFrame(std::string name,  EuclideanGeometry* space) : Frame(name, space) {};
    EuclideanGeometryFrame(){};
	/*std::string toString() const override {
        std::string parentName = ((EuclideanGeometry*)this->space_)->getName();
		return "@@EuclideanGeometryFrame  " + this->getName() + "(" + parentName + (this->parent_? "," + parentName + "." + this->parent_->getName() : "") + ")";
	}*/

private:
};



class EuclideanGeometryStandardFrame : public StandardFrame, public EuclideanGeometryFrame {
public:
	EuclideanGeometryStandardFrame(EuclideanGeometry* space) : StandardFrame(space) {};
	/*std::string toString() const override {
        std::string parentName = ((EuclideanGeometry*)this->space_)->getName();
		return "@@EuclideanGeometryFrame  " + this->getName() + "(" + parentName + (this->parent_? "," + parentName + "." + this->parent_->getName() : "") + ")";
	}*/

    virtual std::string getName() const override {
        return StandardFrame::getName();
    };

    virtual std::string toString() const override {
        return std::string("EuclideanGeometryStandardFrame ") + StandardFrame::toString();
    };

private:
};



class EuclideanGeometryAliasedFrame : public AliasedFrame, public EuclideanGeometryFrame {
public:
	EuclideanGeometryAliasedFrame(std::string name,  EuclideanGeometry* space, EuclideanGeometryFrame* aliased, domain::MeasurementSystem* ms, AxisOrientation* ax) : AliasedFrame(name, space, aliased,  ms, ax) {};
	/*std::string toString() const override {
        std::string parentName = ((EuclideanGeometry*)this->space_)->getName();
		return "@@EuclideanGeometryFrame  " + this->getName() + "(" + parentName + (this->parent_? "," + parentName + "." + this->parent_->getName() : "") + ")";
	}*/
    virtual std::string toString() const override {
        return std::string("EuclideanGeometryAliasedFrame ") + AliasedFrame::toString();
    };
    virtual std::string getName() const override {
        return AliasedFrame::getName();
    };

private:
};



class EuclideanGeometryDerivedFrame : public DerivedFrame, public EuclideanGeometryFrame {
public:
	EuclideanGeometryDerivedFrame(std::string name,  EuclideanGeometry* space, EuclideanGeometryFrame* parent, MeasurementSystem* ms, AxisOrientation* ax) : DerivedFrame(name, space, parent, ms, ax) {};
	/*std::string toString() const override {
        std::string parentName = ((EuclideanGeometry*)this->space_)->getName();
		return "@@EuclideanGeometryFrame  " + this->getName() + "(" + parentName + (this->parent_? "," + parentName + "." + this->parent_->getName() : "") + ")";
	}*/
    virtual std::string toString() const override {
        return std::string("EuclideanGeometryDerivedFrame ") + DerivedFrame::toString();
    };
    virtual std::string getName() const override {
        return DerivedFrame::getName();
    };

private:
};




template <class ValueType, int ValueCount>
class EuclideanGeometryRotation : public ValueObject<ValueType,ValueCount> {
public:
    EuclideanGeometryRotation(EuclideanGeometry* s, std::initializer_list<DomainObject*> args) : 
			ValueObject<ValueType,ValueCount>::ValueObject(args), space_(s)   {}
    EuclideanGeometryRotation(std::initializer_list<DomainObject*> args ) :
	 		ValueObject<ValueType,ValueCount>::ValueObject(args) {}
	virtual ~EuclideanGeometryRotation(){}
    std::string toString() override {
        return "@@EuclideanGeometryRotation(" + (space_?space_->getName():"Missing Space")+","+ValueObject<ValueType,ValueCount>::toString() + ")";
    }

    EuclideanGeometry* getSpace() const {return this->space_;};
    
    
    
    
private:
    EuclideanGeometry* space_; 
    
    
    
    
};




template <class ValueType, int ValueCount>
class EuclideanGeometryOrientation : public ValueObject<ValueType,ValueCount> {
public:
    EuclideanGeometryOrientation(EuclideanGeometry* s, std::initializer_list<DomainObject*> args) : 
			ValueObject<ValueType,ValueCount>::ValueObject(args), space_(s)   {}
    EuclideanGeometryOrientation(std::initializer_list<DomainObject*> args ) :
	 		ValueObject<ValueType,ValueCount>::ValueObject(args) {}
	virtual ~EuclideanGeometryOrientation(){}
    std::string toString() override {
        return "@@EuclideanGeometryOrientation(" + (space_?space_->getName():"Missing Space")+","+ValueObject<ValueType,ValueCount>::toString() + ")";
    }

    EuclideanGeometry* getSpace() const {return this->space_;};
    
    
    
    
private:
    EuclideanGeometry* space_; 
    
    
    
    
};




template <class ValueType, int ValueCount>
class EuclideanGeometryTransform : public ValueObject<ValueType,ValueCount> {
public:
    EuclideanGeometryTransform(EuclideanGeometry* s,EuclideanGeometryFrame* from,EuclideanGeometryFrame* to, std::initializer_list<DomainObject*> args) : 
			ValueObject<ValueType,ValueCount>::ValueObject(args), space_(s),from_(from),to_(to)   {}
    EuclideanGeometryTransform(std::initializer_list<DomainObject*> args ) :
	 		ValueObject<ValueType,ValueCount>::ValueObject(args) {}
	virtual ~EuclideanGeometryTransform(){}
    std::string toString() override {
        return "@@EuclideanGeometryTransform(" + (space_?space_->getName():"Missing Space")+","+ValueObject<ValueType,ValueCount>::toString() + ")";
    }

    EuclideanGeometry* getSpace() const {return this->space_;};
    EuclideanGeometryFrame* getFrom() const {return this->from_;};
    EuclideanGeometryFrame* getTo() const {return this->to_;};
    
    
private:
    EuclideanGeometry* space_; 
    
    
    EuclideanGeometryFrame* from_;
    EuclideanGeometryFrame* to_;
};




template <class ValueType, int ValueCount>
class EuclideanGeometryCoordinatePoint : public ValueObject<ValueType,ValueCount> {
public:
    EuclideanGeometryCoordinatePoint(EuclideanGeometry* s, std::initializer_list<DomainObject*> args) : 
			ValueObject<ValueType,ValueCount>::ValueObject(args), space_(s)   {}
    EuclideanGeometryCoordinatePoint(std::initializer_list<DomainObject*> args ) :
	 		ValueObject<ValueType,ValueCount>::ValueObject(args) {}
	virtual ~EuclideanGeometryCoordinatePoint(){}
    std::string toString() override {
        return "@@EuclideanGeometryCoordinatePoint(" + (space_?space_->getName():"Missing Space")+","+ValueObject<ValueType,ValueCount>::toString()+","+(frame_?frame_->getName():"") + ")";
    }

    EuclideanGeometry* getSpace() const {return this->space_;};
    
    
    EuclideanGeometryFrame* getFrame() const { return this->frame_; };
    void setFrame(EuclideanGeometryFrame* frame){
            this->frame_ = frame;
        };
private:
    EuclideanGeometry* space_; 
    EuclideanGeometryFrame* frame_;
    
    
    
};




template <class ValueType, int ValueCount>
class EuclideanGeometryCoordinateVector : public ValueObject<ValueType,ValueCount> {
public:
    EuclideanGeometryCoordinateVector(EuclideanGeometry* s, std::initializer_list<DomainObject*> args) : 
			ValueObject<ValueType,ValueCount>::ValueObject(args), space_(s)   {}
    EuclideanGeometryCoordinateVector(std::initializer_list<DomainObject*> args ) :
	 		ValueObject<ValueType,ValueCount>::ValueObject(args) {}
	virtual ~EuclideanGeometryCoordinateVector(){}
    std::string toString() override {
        return "@@EuclideanGeometryCoordinateVector(" + (space_?space_->getName():"Missing Space")+","+ValueObject<ValueType,ValueCount>::toString()+","+(frame_?frame_->getName():"") + ")";
    }

    EuclideanGeometry* getSpace() const {return this->space_;};
    
    
    EuclideanGeometryFrame* getFrame() const { return this->frame_; };
    void setFrame(EuclideanGeometryFrame* frame){
            this->frame_ = frame;
        };
private:
    EuclideanGeometry* space_; 
    EuclideanGeometryFrame* frame_;
    
    
    
};




template <class ValueType, int ValueCount>
class EuclideanGeometryScalar : public ValueObject<ValueType,ValueCount> {
public:
    EuclideanGeometryScalar(EuclideanGeometry* s, std::initializer_list<DomainObject*> args) : 
			ValueObject<ValueType,ValueCount>::ValueObject(args), space_(s)   {}
    EuclideanGeometryScalar(std::initializer_list<DomainObject*> args ) :
	 		ValueObject<ValueType,ValueCount>::ValueObject(args) {}
	virtual ~EuclideanGeometryScalar(){}
    std::string toString() override {
        return "@@EuclideanGeometryScalar(" + (space_?space_->getName():"Missing Space")+","+ValueObject<ValueType,ValueCount>::toString() + ")";
    }

    EuclideanGeometry* getSpace() const {return this->space_;};
    
    
    
    
private:
    EuclideanGeometry* space_; 
    
    
    
    
};




template <class ValueType, int ValueCount>
class EuclideanGeometryQuantity : public ValueObject<ValueType,ValueCount> {
public:
    EuclideanGeometryQuantity(EuclideanGeometry* s, std::initializer_list<DomainObject*> args) : 
			ValueObject<ValueType,ValueCount>::ValueObject(args), space_(s)   {}
    EuclideanGeometryQuantity(std::initializer_list<DomainObject*> args ) :
	 		ValueObject<ValueType,ValueCount>::ValueObject(args) {}
	virtual ~EuclideanGeometryQuantity(){}
    std::string toString() override {
        return "@@EuclideanGeometryQuantity(" + (space_?space_->getName():"Missing Space")+","+ValueObject<ValueType,ValueCount>::toString() + ")";
    }

    EuclideanGeometry* getSpace() const {return this->space_;};
    
    
    
    
private:
    EuclideanGeometry* space_; 
    
    
    
    
};


class ClassicalTime : public Space {
    public:
	    ClassicalTime(std::string name) : Space(name, 1) {};
	    std::string getName() const override { return name_; }; 
	    
        void addFrame(ClassicalTimeFrame* frame);
	    std::string toString() const override {
		    return "@@ClassicalTime  " + getName()   + "(" + ")"; 
	    }

    private:
    };


class ClassicalTimeFrame : public Frame {
public:
	ClassicalTimeFrame(std::string name,  ClassicalTime* space) : Frame(name, space) {};
    ClassicalTimeFrame(){};
	/*std::string toString() const override {
        std::string parentName = ((ClassicalTime*)this->space_)->getName();
		return "@@ClassicalTimeFrame  " + this->getName() + "(" + parentName + (this->parent_? "," + parentName + "." + this->parent_->getName() : "") + ")";
	}*/

private:
};



class ClassicalTimeStandardFrame : public StandardFrame, public ClassicalTimeFrame {
public:
	ClassicalTimeStandardFrame(ClassicalTime* space) : StandardFrame(space) {};
	/*std::string toString() const override {
        std::string parentName = ((ClassicalTime*)this->space_)->getName();
		return "@@ClassicalTimeFrame  " + this->getName() + "(" + parentName + (this->parent_? "," + parentName + "." + this->parent_->getName() : "") + ")";
	}*/

    virtual std::string getName() const override {
        return StandardFrame::getName();
    };

    virtual std::string toString() const override {
        return std::string("ClassicalTimeStandardFrame ") + StandardFrame::toString();
    };

private:
};



class ClassicalTimeAliasedFrame : public AliasedFrame, public ClassicalTimeFrame {
public:
	ClassicalTimeAliasedFrame(std::string name,  ClassicalTime* space, ClassicalTimeFrame* aliased, domain::MeasurementSystem* ms, AxisOrientation* ax) : AliasedFrame(name, space, aliased,  ms, ax) {};
	/*std::string toString() const override {
        std::string parentName = ((ClassicalTime*)this->space_)->getName();
		return "@@ClassicalTimeFrame  " + this->getName() + "(" + parentName + (this->parent_? "," + parentName + "." + this->parent_->getName() : "") + ")";
	}*/
    virtual std::string toString() const override {
        return std::string("ClassicalTimeAliasedFrame ") + AliasedFrame::toString();
    };
    virtual std::string getName() const override {
        return AliasedFrame::getName();
    };

private:
};



class ClassicalTimeDerivedFrame : public DerivedFrame, public ClassicalTimeFrame {
public:
	ClassicalTimeDerivedFrame(std::string name,  ClassicalTime* space, ClassicalTimeFrame* parent, MeasurementSystem* ms, AxisOrientation* ax) : DerivedFrame(name, space, parent, ms, ax) {};
	/*std::string toString() const override {
        std::string parentName = ((ClassicalTime*)this->space_)->getName();
		return "@@ClassicalTimeFrame  " + this->getName() + "(" + parentName + (this->parent_? "," + parentName + "." + this->parent_->getName() : "") + ")";
	}*/
    virtual std::string toString() const override {
        return std::string("ClassicalTimeDerivedFrame ") + DerivedFrame::toString();
    };
    virtual std::string getName() const override {
        return DerivedFrame::getName();
    };

private:
};




template <class ValueType, int ValueCount>
class ClassicalTimeTransform : public ValueObject<ValueType,ValueCount> {
public:
    ClassicalTimeTransform(ClassicalTime* s,ClassicalTimeFrame* from,ClassicalTimeFrame* to, std::initializer_list<DomainObject*> args) : 
			ValueObject<ValueType,ValueCount>::ValueObject(args), space_(s),from_(from),to_(to)   {}
    ClassicalTimeTransform(std::initializer_list<DomainObject*> args ) :
	 		ValueObject<ValueType,ValueCount>::ValueObject(args) {}
	virtual ~ClassicalTimeTransform(){}
    std::string toString() override {
        return "@@ClassicalTimeTransform(" + (space_?space_->getName():"Missing Space")+","+ValueObject<ValueType,ValueCount>::toString() + ")";
    }

    ClassicalTime* getSpace() const {return this->space_;};
    ClassicalTimeFrame* getFrom() const {return this->from_;};
    ClassicalTimeFrame* getTo() const {return this->to_;};
    
    
private:
    ClassicalTime* space_; 
    
    
    ClassicalTimeFrame* from_;
    ClassicalTimeFrame* to_;
};




template <class ValueType, int ValueCount>
class ClassicalTimeCoordinatePoint : public ValueObject<ValueType,ValueCount> {
public:
    ClassicalTimeCoordinatePoint(ClassicalTime* s, std::initializer_list<DomainObject*> args) : 
			ValueObject<ValueType,ValueCount>::ValueObject(args), space_(s)   {}
    ClassicalTimeCoordinatePoint(std::initializer_list<DomainObject*> args ) :
	 		ValueObject<ValueType,ValueCount>::ValueObject(args) {}
	virtual ~ClassicalTimeCoordinatePoint(){}
    std::string toString() override {
        return "@@ClassicalTimeCoordinatePoint(" + (space_?space_->getName():"Missing Space")+","+ValueObject<ValueType,ValueCount>::toString()+","+(frame_?frame_->getName():"") + ")";
    }

    ClassicalTime* getSpace() const {return this->space_;};
    
    
    ClassicalTimeFrame* getFrame() const { return this->frame_; };
    void setFrame(ClassicalTimeFrame* frame){
            this->frame_ = frame;
        };
private:
    ClassicalTime* space_; 
    ClassicalTimeFrame* frame_;
    
    
    
};




template <class ValueType, int ValueCount>
class ClassicalTimeCoordinateVector : public ValueObject<ValueType,ValueCount> {
public:
    ClassicalTimeCoordinateVector(ClassicalTime* s, std::initializer_list<DomainObject*> args) : 
			ValueObject<ValueType,ValueCount>::ValueObject(args), space_(s)   {}
    ClassicalTimeCoordinateVector(std::initializer_list<DomainObject*> args ) :
	 		ValueObject<ValueType,ValueCount>::ValueObject(args) {}
	virtual ~ClassicalTimeCoordinateVector(){}
    std::string toString() override {
        return "@@ClassicalTimeCoordinateVector(" + (space_?space_->getName():"Missing Space")+","+ValueObject<ValueType,ValueCount>::toString()+","+(frame_?frame_->getName():"") + ")";
    }

    ClassicalTime* getSpace() const {return this->space_;};
    
    
    ClassicalTimeFrame* getFrame() const { return this->frame_; };
    void setFrame(ClassicalTimeFrame* frame){
            this->frame_ = frame;
        };
private:
    ClassicalTime* space_; 
    ClassicalTimeFrame* frame_;
    
    
    
};




template <class ValueType, int ValueCount>
class ClassicalTimeScalar : public ValueObject<ValueType,ValueCount> {
public:
    ClassicalTimeScalar(ClassicalTime* s, std::initializer_list<DomainObject*> args) : 
			ValueObject<ValueType,ValueCount>::ValueObject(args), space_(s)   {}
    ClassicalTimeScalar(std::initializer_list<DomainObject*> args ) :
	 		ValueObject<ValueType,ValueCount>::ValueObject(args) {}
	virtual ~ClassicalTimeScalar(){}
    std::string toString() override {
        return "@@ClassicalTimeScalar(" + (space_?space_->getName():"Missing Space")+","+ValueObject<ValueType,ValueCount>::toString() + ")";
    }

    ClassicalTime* getSpace() const {return this->space_;};
    
    
    
    
private:
    ClassicalTime* space_; 
    
    
    
    
};




template <class ValueType, int ValueCount>
class ClassicalTimeQuantity : public ValueObject<ValueType,ValueCount> {
public:
    ClassicalTimeQuantity(ClassicalTime* s, std::initializer_list<DomainObject*> args) : 
			ValueObject<ValueType,ValueCount>::ValueObject(args), space_(s)   {}
    ClassicalTimeQuantity(std::initializer_list<DomainObject*> args ) :
	 		ValueObject<ValueType,ValueCount>::ValueObject(args) {}
	virtual ~ClassicalTimeQuantity(){}
    std::string toString() override {
        return "@@ClassicalTimeQuantity(" + (space_?space_->getName():"Missing Space")+","+ValueObject<ValueType,ValueCount>::toString() + ")";
    }

    ClassicalTime* getSpace() const {return this->space_;};
    
    
    
    
private:
    ClassicalTime* space_; 
    
    
    
    
};


class EuclideanGeometry3 : public Space {
    public:
	    EuclideanGeometry3(std::string name) : Space(name, 3) {};
	    std::string getName() const override { return name_; }; 
	    
        void addFrame(EuclideanGeometry3Frame* frame);
	    std::string toString() const override {
		    return "@@EuclideanGeometry3  " + getName()   + "(" + ")"; 
	    }

    private:
    };


class EuclideanGeometry3Frame : public Frame {
public:
	EuclideanGeometry3Frame(std::string name,  EuclideanGeometry3* space) : Frame(name, space) {};
    EuclideanGeometry3Frame(){};
	/*std::string toString() const override {
        std::string parentName = ((EuclideanGeometry3*)this->space_)->getName();
		return "@@EuclideanGeometry3Frame  " + this->getName() + "(" + parentName + (this->parent_? "," + parentName + "." + this->parent_->getName() : "") + ")";
	}*/

private:
};



class EuclideanGeometry3StandardFrame : public StandardFrame, public EuclideanGeometry3Frame {
public:
	EuclideanGeometry3StandardFrame(EuclideanGeometry3* space) : StandardFrame(space) {};
	/*std::string toString() const override {
        std::string parentName = ((EuclideanGeometry3*)this->space_)->getName();
		return "@@EuclideanGeometry3Frame  " + this->getName() + "(" + parentName + (this->parent_? "," + parentName + "." + this->parent_->getName() : "") + ")";
	}*/

    virtual std::string getName() const override {
        return StandardFrame::getName();
    };

    virtual std::string toString() const override {
        return std::string("EuclideanGeometry3StandardFrame ") + StandardFrame::toString();
    };

private:
};



class EuclideanGeometry3AliasedFrame : public AliasedFrame, public EuclideanGeometry3Frame {
public:
	EuclideanGeometry3AliasedFrame(std::string name,  EuclideanGeometry3* space, EuclideanGeometry3Frame* aliased, domain::MeasurementSystem* ms, AxisOrientation* ax) : AliasedFrame(name, space, aliased,  ms, ax) {};
	/*std::string toString() const override {
        std::string parentName = ((EuclideanGeometry3*)this->space_)->getName();
		return "@@EuclideanGeometry3Frame  " + this->getName() + "(" + parentName + (this->parent_? "," + parentName + "." + this->parent_->getName() : "") + ")";
	}*/
    virtual std::string toString() const override {
        return std::string("EuclideanGeometry3AliasedFrame ") + AliasedFrame::toString();
    };
    virtual std::string getName() const override {
        return AliasedFrame::getName();
    };

private:
};



class EuclideanGeometry3DerivedFrame : public DerivedFrame, public EuclideanGeometry3Frame {
public:
	EuclideanGeometry3DerivedFrame(std::string name,  EuclideanGeometry3* space, EuclideanGeometry3Frame* parent, MeasurementSystem* ms, AxisOrientation* ax) : DerivedFrame(name, space, parent, ms, ax) {};
	/*std::string toString() const override {
        std::string parentName = ((EuclideanGeometry3*)this->space_)->getName();
		return "@@EuclideanGeometry3Frame  " + this->getName() + "(" + parentName + (this->parent_? "," + parentName + "." + this->parent_->getName() : "") + ")";
	}*/
    virtual std::string toString() const override {
        return std::string("EuclideanGeometry3DerivedFrame ") + DerivedFrame::toString();
    };
    virtual std::string getName() const override {
        return DerivedFrame::getName();
    };

private:
};




template <class ValueType, int ValueCount>
class EuclideanGeometry3Rotation : public ValueObject<ValueType,ValueCount> {
public:
    EuclideanGeometry3Rotation(EuclideanGeometry3* s, std::initializer_list<DomainObject*> args) : 
			ValueObject<ValueType,ValueCount>::ValueObject(args), space_(s)   {}
    EuclideanGeometry3Rotation(std::initializer_list<DomainObject*> args ) :
	 		ValueObject<ValueType,ValueCount>::ValueObject(args) {}
	virtual ~EuclideanGeometry3Rotation(){}
    std::string toString() override {
        return "@@EuclideanGeometry3Rotation(" + (space_?space_->getName():"Missing Space")+","+ValueObject<ValueType,ValueCount>::toString() + ")";
    }

    EuclideanGeometry3* getSpace() const {return this->space_;};
    
    
    
    
private:
    EuclideanGeometry3* space_; 
    
    
    
    
};




template <class ValueType, int ValueCount>
class EuclideanGeometry3Orientation : public ValueObject<ValueType,ValueCount> {
public:
    EuclideanGeometry3Orientation(EuclideanGeometry3* s, std::initializer_list<DomainObject*> args) : 
			ValueObject<ValueType,ValueCount>::ValueObject(args), space_(s)   {}
    EuclideanGeometry3Orientation(std::initializer_list<DomainObject*> args ) :
	 		ValueObject<ValueType,ValueCount>::ValueObject(args) {}
	virtual ~EuclideanGeometry3Orientation(){}
    std::string toString() override {
        return "@@EuclideanGeometry3Orientation(" + (space_?space_->getName():"Missing Space")+","+ValueObject<ValueType,ValueCount>::toString() + ")";
    }

    EuclideanGeometry3* getSpace() const {return this->space_;};
    
    
    
    
private:
    EuclideanGeometry3* space_; 
    
    
    
    
};




template <class ValueType, int ValueCount>
class EuclideanGeometry3Transform : public ValueObject<ValueType,ValueCount> {
public:
    EuclideanGeometry3Transform(EuclideanGeometry3* s,EuclideanGeometry3Frame* from,EuclideanGeometry3Frame* to, std::initializer_list<DomainObject*> args) : 
			ValueObject<ValueType,ValueCount>::ValueObject(args), space_(s),from_(from),to_(to)   {}
    EuclideanGeometry3Transform(std::initializer_list<DomainObject*> args ) :
	 		ValueObject<ValueType,ValueCount>::ValueObject(args) {}
	virtual ~EuclideanGeometry3Transform(){}
    std::string toString() override {
        return "@@EuclideanGeometry3Transform(" + (space_?space_->getName():"Missing Space")+","+ValueObject<ValueType,ValueCount>::toString() + ")";
    }

    EuclideanGeometry3* getSpace() const {return this->space_;};
    EuclideanGeometry3Frame* getFrom() const {return this->from_;};
    EuclideanGeometry3Frame* getTo() const {return this->to_;};
    
    
private:
    EuclideanGeometry3* space_; 
    
    
    EuclideanGeometry3Frame* from_;
    EuclideanGeometry3Frame* to_;
};




template <class ValueType, int ValueCount>
class EuclideanGeometry3CoordinatePoint : public ValueObject<ValueType,ValueCount> {
public:
    EuclideanGeometry3CoordinatePoint(EuclideanGeometry3* s, std::initializer_list<DomainObject*> args) : 
			ValueObject<ValueType,ValueCount>::ValueObject(args), space_(s)   {}
    EuclideanGeometry3CoordinatePoint(std::initializer_list<DomainObject*> args ) :
	 		ValueObject<ValueType,ValueCount>::ValueObject(args) {}
	virtual ~EuclideanGeometry3CoordinatePoint(){}
    std::string toString() override {
        return "@@EuclideanGeometry3CoordinatePoint(" + (space_?space_->getName():"Missing Space")+","+ValueObject<ValueType,ValueCount>::toString()+","+(frame_?frame_->getName():"") + ")";
    }

    EuclideanGeometry3* getSpace() const {return this->space_;};
    
    
    EuclideanGeometry3Frame* getFrame() const { return this->frame_; };
    void setFrame(EuclideanGeometry3Frame* frame){
            this->frame_ = frame;
        };
private:
    EuclideanGeometry3* space_; 
    EuclideanGeometry3Frame* frame_;
    
    
    
};




template <class ValueType, int ValueCount>
class EuclideanGeometry3CoordinateVector : public ValueObject<ValueType,ValueCount> {
public:
    EuclideanGeometry3CoordinateVector(EuclideanGeometry3* s, std::initializer_list<DomainObject*> args) : 
			ValueObject<ValueType,ValueCount>::ValueObject(args), space_(s)   {}
    EuclideanGeometry3CoordinateVector(std::initializer_list<DomainObject*> args ) :
	 		ValueObject<ValueType,ValueCount>::ValueObject(args) {}
	virtual ~EuclideanGeometry3CoordinateVector(){}
    std::string toString() override {
        return "@@EuclideanGeometry3CoordinateVector(" + (space_?space_->getName():"Missing Space")+","+ValueObject<ValueType,ValueCount>::toString()+","+(frame_?frame_->getName():"") + ")";
    }

    EuclideanGeometry3* getSpace() const {return this->space_;};
    
    
    EuclideanGeometry3Frame* getFrame() const { return this->frame_; };
    void setFrame(EuclideanGeometry3Frame* frame){
            this->frame_ = frame;
        };
private:
    EuclideanGeometry3* space_; 
    EuclideanGeometry3Frame* frame_;
    
    
    
};




template <class ValueType, int ValueCount>
class EuclideanGeometry3Scalar : public ValueObject<ValueType,ValueCount> {
public:
    EuclideanGeometry3Scalar(EuclideanGeometry3* s, std::initializer_list<DomainObject*> args) : 
			ValueObject<ValueType,ValueCount>::ValueObject(args), space_(s)   {}
    EuclideanGeometry3Scalar(std::initializer_list<DomainObject*> args ) :
	 		ValueObject<ValueType,ValueCount>::ValueObject(args) {}
	virtual ~EuclideanGeometry3Scalar(){}
    std::string toString() override {
        return "@@EuclideanGeometry3Scalar(" + (space_?space_->getName():"Missing Space")+","+ValueObject<ValueType,ValueCount>::toString() + ")";
    }

    EuclideanGeometry3* getSpace() const {return this->space_;};
    
    
    
    
private:
    EuclideanGeometry3* space_; 
    
    
    
    
};




template <class ValueType, int ValueCount>
class EuclideanGeometry3Quantity : public ValueObject<ValueType,ValueCount> {
public:
    EuclideanGeometry3Quantity(EuclideanGeometry3* s, std::initializer_list<DomainObject*> args) : 
			ValueObject<ValueType,ValueCount>::ValueObject(args), space_(s)   {}
    EuclideanGeometry3Quantity(std::initializer_list<DomainObject*> args ) :
	 		ValueObject<ValueType,ValueCount>::ValueObject(args) {}
	virtual ~EuclideanGeometry3Quantity(){}
    std::string toString() override {
        return "@@EuclideanGeometry3Quantity(" + (space_?space_->getName():"Missing Space")+","+ValueObject<ValueType,ValueCount>::toString() + ")";
    }

    EuclideanGeometry3* getSpace() const {return this->space_;};
    
    
    
    
private:
    EuclideanGeometry3* space_; 
    
    
    
    
};


class ClassicalVelocity : public DerivedSpace {
    public:
	    
        ClassicalVelocity(std::string name, Space* base1, Space* base2) : DerivedSpace(name, base1, base2) {};
        void addFrame(ClassicalVelocityFrame* frame);
	    std::string toString() const override {
		    return "@@ClassicalVelocity  " + getName()   + "(" + this->base_1->getName() + "," + this->base_2->getName() + ")"; 
	    }

    private:
    };


class ClassicalVelocityFrame : public Frame {
public:
	ClassicalVelocityFrame(std::string name,  ClassicalVelocity* space) : Frame(name, space) {};
    ClassicalVelocityFrame(){};
	/*std::string toString() const override {
        std::string parentName = ((ClassicalVelocity*)this->space_)->getName();
		return "@@ClassicalVelocityFrame  " + this->getName() + "(" + parentName + (this->parent_? "," + parentName + "." + this->parent_->getName() : "") + ")";
	}*/

private:
};



class ClassicalVelocityStandardFrame : public StandardFrame, public ClassicalVelocityFrame {
public:
	ClassicalVelocityStandardFrame(ClassicalVelocity* space) : StandardFrame(space) {};
	/*std::string toString() const override {
        std::string parentName = ((ClassicalVelocity*)this->space_)->getName();
		return "@@ClassicalVelocityFrame  " + this->getName() + "(" + parentName + (this->parent_? "," + parentName + "." + this->parent_->getName() : "") + ")";
	}*/

    virtual std::string getName() const override {
        return StandardFrame::getName();
    };

    virtual std::string toString() const override {
        return std::string("ClassicalVelocityStandardFrame ") + StandardFrame::toString();
    };

private:
};



class ClassicalVelocityAliasedFrame : public AliasedFrame, public ClassicalVelocityFrame {
public:
	ClassicalVelocityAliasedFrame(std::string name,  ClassicalVelocity* space, ClassicalVelocityFrame* aliased, domain::MeasurementSystem* ms, AxisOrientation* ax) : AliasedFrame(name, space, aliased,  ms, ax) {};
	/*std::string toString() const override {
        std::string parentName = ((ClassicalVelocity*)this->space_)->getName();
		return "@@ClassicalVelocityFrame  " + this->getName() + "(" + parentName + (this->parent_? "," + parentName + "." + this->parent_->getName() : "") + ")";
	}*/
    virtual std::string toString() const override {
        return std::string("ClassicalVelocityAliasedFrame ") + AliasedFrame::toString();
    };
    virtual std::string getName() const override {
        return AliasedFrame::getName();
    };

private:
};



class ClassicalVelocityDerivedFrame : public DerivedFrame, public ClassicalVelocityFrame {
public:
	ClassicalVelocityDerivedFrame(std::string name,  ClassicalVelocity* space, ClassicalVelocityFrame* parent, MeasurementSystem* ms, AxisOrientation* ax) : DerivedFrame(name, space, parent, ms, ax) {};
	/*std::string toString() const override {
        std::string parentName = ((ClassicalVelocity*)this->space_)->getName();
		return "@@ClassicalVelocityFrame  " + this->getName() + "(" + parentName + (this->parent_? "," + parentName + "." + this->parent_->getName() : "") + ")";
	}*/
    virtual std::string toString() const override {
        return std::string("ClassicalVelocityDerivedFrame ") + DerivedFrame::toString();
    };
    virtual std::string getName() const override {
        return DerivedFrame::getName();
    };

private:
};




template <class ValueType, int ValueCount>
class ClassicalVelocityCoordinateVector : public ValueObject<ValueType,ValueCount> {
public:
    ClassicalVelocityCoordinateVector(ClassicalVelocity* s, std::initializer_list<DomainObject*> args) : 
			ValueObject<ValueType,ValueCount>::ValueObject(args), space_(s)   {}
    ClassicalVelocityCoordinateVector(std::initializer_list<DomainObject*> args ) :
	 		ValueObject<ValueType,ValueCount>::ValueObject(args) {}
	virtual ~ClassicalVelocityCoordinateVector(){}
    std::string toString() override {
        return "@@ClassicalVelocityCoordinateVector(" + (space_?space_->getName():"Missing Space")+","+ValueObject<ValueType,ValueCount>::toString()+","+(frame_?frame_->getName():"") + ")";
    }

    ClassicalVelocity* getSpace() const {return this->space_;};
    
    
    ClassicalVelocityFrame* getFrame() const { return this->frame_; };
    void setFrame(ClassicalVelocityFrame* frame){
            this->frame_ = frame;
        };
private:
    ClassicalVelocity* space_; 
    ClassicalVelocityFrame* frame_;
    
    
    
};




template <class ValueType, int ValueCount>
class ClassicalVelocityScalar : public ValueObject<ValueType,ValueCount> {
public:
    ClassicalVelocityScalar(ClassicalVelocity* s, std::initializer_list<DomainObject*> args) : 
			ValueObject<ValueType,ValueCount>::ValueObject(args), space_(s)   {}
    ClassicalVelocityScalar(std::initializer_list<DomainObject*> args ) :
	 		ValueObject<ValueType,ValueCount>::ValueObject(args) {}
	virtual ~ClassicalVelocityScalar(){}
    std::string toString() override {
        return "@@ClassicalVelocityScalar(" + (space_?space_->getName():"Missing Space")+","+ValueObject<ValueType,ValueCount>::toString() + ")";
    }

    ClassicalVelocity* getSpace() const {return this->space_;};
    
    
    
    
private:
    ClassicalVelocity* space_; 
    
    
    
    
};




template <class ValueType, int ValueCount>
class ClassicalVelocityQuantity : public ValueObject<ValueType,ValueCount> {
public:
    ClassicalVelocityQuantity(ClassicalVelocity* s, std::initializer_list<DomainObject*> args) : 
			ValueObject<ValueType,ValueCount>::ValueObject(args), space_(s)   {}
    ClassicalVelocityQuantity(std::initializer_list<DomainObject*> args ) :
	 		ValueObject<ValueType,ValueCount>::ValueObject(args) {}
	virtual ~ClassicalVelocityQuantity(){}
    std::string toString() override {
        return "@@ClassicalVelocityQuantity(" + (space_?space_->getName():"Missing Space")+","+ValueObject<ValueType,ValueCount>::toString() + ")";
    }

    ClassicalVelocity* getSpace() const {return this->space_;};
    
    
    
    
private:
    ClassicalVelocity* space_; 
    
    
    
    
};


class ClassicalHertz : public Space {
    public:
	    ClassicalHertz(std::string name) : Space(name, 1) {};
	    std::string getName() const override { return name_; }; 
	    
        void addFrame(ClassicalHertzFrame* frame);
	    std::string toString() const override {
		    return "@@ClassicalHertz  " + getName()   + "(" + ")"; 
	    }

    private:
    };


class ClassicalHertzFrame : public Frame {
public:
	ClassicalHertzFrame(std::string name,  ClassicalHertz* space) : Frame(name, space) {};
    ClassicalHertzFrame(){};
	/*std::string toString() const override {
        std::string parentName = ((ClassicalHertz*)this->space_)->getName();
		return "@@ClassicalHertzFrame  " + this->getName() + "(" + parentName + (this->parent_? "," + parentName + "." + this->parent_->getName() : "") + ")";
	}*/

private:
};



class ClassicalHertzStandardFrame : public StandardFrame, public ClassicalHertzFrame {
public:
	ClassicalHertzStandardFrame(ClassicalHertz* space) : StandardFrame(space) {};
	/*std::string toString() const override {
        std::string parentName = ((ClassicalHertz*)this->space_)->getName();
		return "@@ClassicalHertzFrame  " + this->getName() + "(" + parentName + (this->parent_? "," + parentName + "." + this->parent_->getName() : "") + ")";
	}*/

    virtual std::string getName() const override {
        return StandardFrame::getName();
    };

    virtual std::string toString() const override {
        return std::string("ClassicalHertzStandardFrame ") + StandardFrame::toString();
    };

private:
};



class ClassicalHertzAliasedFrame : public AliasedFrame, public ClassicalHertzFrame {
public:
	ClassicalHertzAliasedFrame(std::string name,  ClassicalHertz* space, ClassicalHertzFrame* aliased, domain::MeasurementSystem* ms, AxisOrientation* ax) : AliasedFrame(name, space, aliased,  ms, ax) {};
	/*std::string toString() const override {
        std::string parentName = ((ClassicalHertz*)this->space_)->getName();
		return "@@ClassicalHertzFrame  " + this->getName() + "(" + parentName + (this->parent_? "," + parentName + "." + this->parent_->getName() : "") + ")";
	}*/
    virtual std::string toString() const override {
        return std::string("ClassicalHertzAliasedFrame ") + AliasedFrame::toString();
    };
    virtual std::string getName() const override {
        return AliasedFrame::getName();
    };

private:
};



class ClassicalHertzDerivedFrame : public DerivedFrame, public ClassicalHertzFrame {
public:
	ClassicalHertzDerivedFrame(std::string name,  ClassicalHertz* space, ClassicalHertzFrame* parent, MeasurementSystem* ms, AxisOrientation* ax) : DerivedFrame(name, space, parent, ms, ax) {};
	/*std::string toString() const override {
        std::string parentName = ((ClassicalHertz*)this->space_)->getName();
		return "@@ClassicalHertzFrame  " + this->getName() + "(" + parentName + (this->parent_? "," + parentName + "." + this->parent_->getName() : "") + ")";
	}*/
    virtual std::string toString() const override {
        return std::string("ClassicalHertzDerivedFrame ") + DerivedFrame::toString();
    };
    virtual std::string getName() const override {
        return DerivedFrame::getName();
    };

private:
};




template <class ValueType, int ValueCount>
class ClassicalHertzCoordinateVector : public ValueObject<ValueType,ValueCount> {
public:
    ClassicalHertzCoordinateVector(ClassicalHertz* s, std::initializer_list<DomainObject*> args) : 
			ValueObject<ValueType,ValueCount>::ValueObject(args), space_(s)   {}
    ClassicalHertzCoordinateVector(std::initializer_list<DomainObject*> args ) :
	 		ValueObject<ValueType,ValueCount>::ValueObject(args) {}
	virtual ~ClassicalHertzCoordinateVector(){}
    std::string toString() override {
        return "@@ClassicalHertzCoordinateVector(" + (space_?space_->getName():"Missing Space")+","+ValueObject<ValueType,ValueCount>::toString()+","+(frame_?frame_->getName():"") + ")";
    }

    ClassicalHertz* getSpace() const {return this->space_;};
    
    
    ClassicalHertzFrame* getFrame() const { return this->frame_; };
    void setFrame(ClassicalHertzFrame* frame){
            this->frame_ = frame;
        };
private:
    ClassicalHertz* space_; 
    ClassicalHertzFrame* frame_;
    
    
    
};




template <class ValueType, int ValueCount>
class ClassicalHertzScalar : public ValueObject<ValueType,ValueCount> {
public:
    ClassicalHertzScalar(ClassicalHertz* s, std::initializer_list<DomainObject*> args) : 
			ValueObject<ValueType,ValueCount>::ValueObject(args), space_(s)   {}
    ClassicalHertzScalar(std::initializer_list<DomainObject*> args ) :
	 		ValueObject<ValueType,ValueCount>::ValueObject(args) {}
	virtual ~ClassicalHertzScalar(){}
    std::string toString() override {
        return "@@ClassicalHertzScalar(" + (space_?space_->getName():"Missing Space")+","+ValueObject<ValueType,ValueCount>::toString() + ")";
    }

    ClassicalHertz* getSpace() const {return this->space_;};
    
    
    
    
private:
    ClassicalHertz* space_; 
    
    
    
    
};




template <class ValueType, int ValueCount>
class ClassicalHertzQuantity : public ValueObject<ValueType,ValueCount> {
public:
    ClassicalHertzQuantity(ClassicalHertz* s, std::initializer_list<DomainObject*> args) : 
			ValueObject<ValueType,ValueCount>::ValueObject(args), space_(s)   {}
    ClassicalHertzQuantity(std::initializer_list<DomainObject*> args ) :
	 		ValueObject<ValueType,ValueCount>::ValueObject(args) {}
	virtual ~ClassicalHertzQuantity(){}
    std::string toString() override {
        return "@@ClassicalHertzQuantity(" + (space_?space_->getName():"Missing Space")+","+ValueObject<ValueType,ValueCount>::toString() + ")";
    }

    ClassicalHertz* getSpace() const {return this->space_;};
    
    
    
    
private:
    ClassicalHertz* space_; 
    
    
    
    
};


class ClassicalLuminousIntensity : public Space {
    public:
	    ClassicalLuminousIntensity(std::string name) : Space(name, 1) {};
	    std::string getName() const override { return name_; }; 
	    
        void addFrame(ClassicalLuminousIntensityFrame* frame);
	    std::string toString() const override {
		    return "@@ClassicalLuminousIntensity  " + getName()   + "(" + ")"; 
	    }

    private:
    };


class ClassicalLuminousIntensityFrame : public Frame {
public:
	ClassicalLuminousIntensityFrame(std::string name,  ClassicalLuminousIntensity* space) : Frame(name, space) {};
    ClassicalLuminousIntensityFrame(){};
	/*std::string toString() const override {
        std::string parentName = ((ClassicalLuminousIntensity*)this->space_)->getName();
		return "@@ClassicalLuminousIntensityFrame  " + this->getName() + "(" + parentName + (this->parent_? "," + parentName + "." + this->parent_->getName() : "") + ")";
	}*/

private:
};



class ClassicalLuminousIntensityStandardFrame : public StandardFrame, public ClassicalLuminousIntensityFrame {
public:
	ClassicalLuminousIntensityStandardFrame(ClassicalLuminousIntensity* space) : StandardFrame(space) {};
	/*std::string toString() const override {
        std::string parentName = ((ClassicalLuminousIntensity*)this->space_)->getName();
		return "@@ClassicalLuminousIntensityFrame  " + this->getName() + "(" + parentName + (this->parent_? "," + parentName + "." + this->parent_->getName() : "") + ")";
	}*/

    virtual std::string getName() const override {
        return StandardFrame::getName();
    };

    virtual std::string toString() const override {
        return std::string("ClassicalLuminousIntensityStandardFrame ") + StandardFrame::toString();
    };

private:
};



class ClassicalLuminousIntensityAliasedFrame : public AliasedFrame, public ClassicalLuminousIntensityFrame {
public:
	ClassicalLuminousIntensityAliasedFrame(std::string name,  ClassicalLuminousIntensity* space, ClassicalLuminousIntensityFrame* aliased, domain::MeasurementSystem* ms, AxisOrientation* ax) : AliasedFrame(name, space, aliased,  ms, ax) {};
	/*std::string toString() const override {
        std::string parentName = ((ClassicalLuminousIntensity*)this->space_)->getName();
		return "@@ClassicalLuminousIntensityFrame  " + this->getName() + "(" + parentName + (this->parent_? "," + parentName + "." + this->parent_->getName() : "") + ")";
	}*/
    virtual std::string toString() const override {
        return std::string("ClassicalLuminousIntensityAliasedFrame ") + AliasedFrame::toString();
    };
    virtual std::string getName() const override {
        return AliasedFrame::getName();
    };

private:
};



class ClassicalLuminousIntensityDerivedFrame : public DerivedFrame, public ClassicalLuminousIntensityFrame {
public:
	ClassicalLuminousIntensityDerivedFrame(std::string name,  ClassicalLuminousIntensity* space, ClassicalLuminousIntensityFrame* parent, MeasurementSystem* ms, AxisOrientation* ax) : DerivedFrame(name, space, parent, ms, ax) {};
	/*std::string toString() const override {
        std::string parentName = ((ClassicalLuminousIntensity*)this->space_)->getName();
		return "@@ClassicalLuminousIntensityFrame  " + this->getName() + "(" + parentName + (this->parent_? "," + parentName + "." + this->parent_->getName() : "") + ")";
	}*/
    virtual std::string toString() const override {
        return std::string("ClassicalLuminousIntensityDerivedFrame ") + DerivedFrame::toString();
    };
    virtual std::string getName() const override {
        return DerivedFrame::getName();
    };

private:
};




template <class ValueType, int ValueCount>
class ClassicalLuminousIntensityCoordinateVector : public ValueObject<ValueType,ValueCount> {
public:
    ClassicalLuminousIntensityCoordinateVector(ClassicalLuminousIntensity* s, std::initializer_list<DomainObject*> args) : 
			ValueObject<ValueType,ValueCount>::ValueObject(args), space_(s)   {}
    ClassicalLuminousIntensityCoordinateVector(std::initializer_list<DomainObject*> args ) :
	 		ValueObject<ValueType,ValueCount>::ValueObject(args) {}
	virtual ~ClassicalLuminousIntensityCoordinateVector(){}
    std::string toString() override {
        return "@@ClassicalLuminousIntensityCoordinateVector(" + (space_?space_->getName():"Missing Space")+","+ValueObject<ValueType,ValueCount>::toString()+","+(frame_?frame_->getName():"") + ")";
    }

    ClassicalLuminousIntensity* getSpace() const {return this->space_;};
    
    
    ClassicalLuminousIntensityFrame* getFrame() const { return this->frame_; };
    void setFrame(ClassicalLuminousIntensityFrame* frame){
            this->frame_ = frame;
        };
private:
    ClassicalLuminousIntensity* space_; 
    ClassicalLuminousIntensityFrame* frame_;
    
    
    
};




template <class ValueType, int ValueCount>
class ClassicalLuminousIntensityScalar : public ValueObject<ValueType,ValueCount> {
public:
    ClassicalLuminousIntensityScalar(ClassicalLuminousIntensity* s, std::initializer_list<DomainObject*> args) : 
			ValueObject<ValueType,ValueCount>::ValueObject(args), space_(s)   {}
    ClassicalLuminousIntensityScalar(std::initializer_list<DomainObject*> args ) :
	 		ValueObject<ValueType,ValueCount>::ValueObject(args) {}
	virtual ~ClassicalLuminousIntensityScalar(){}
    std::string toString() override {
        return "@@ClassicalLuminousIntensityScalar(" + (space_?space_->getName():"Missing Space")+","+ValueObject<ValueType,ValueCount>::toString() + ")";
    }

    ClassicalLuminousIntensity* getSpace() const {return this->space_;};
    
    
    
    
private:
    ClassicalLuminousIntensity* space_; 
    
    
    
    
};




template <class ValueType, int ValueCount>
class ClassicalLuminousIntensityQuantity : public ValueObject<ValueType,ValueCount> {
public:
    ClassicalLuminousIntensityQuantity(ClassicalLuminousIntensity* s, std::initializer_list<DomainObject*> args) : 
			ValueObject<ValueType,ValueCount>::ValueObject(args), space_(s)   {}
    ClassicalLuminousIntensityQuantity(std::initializer_list<DomainObject*> args ) :
	 		ValueObject<ValueType,ValueCount>::ValueObject(args) {}
	virtual ~ClassicalLuminousIntensityQuantity(){}
    std::string toString() override {
        return "@@ClassicalLuminousIntensityQuantity(" + (space_?space_->getName():"Missing Space")+","+ValueObject<ValueType,ValueCount>::toString() + ")";
    }

    ClassicalLuminousIntensity* getSpace() const {return this->space_;};
    
    
    
    
private:
    ClassicalLuminousIntensity* space_; 
    
    
    
    
};

} // end namespace

#endif