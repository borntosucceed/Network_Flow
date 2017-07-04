# -*- coding: utf-8 -*-
"""
Created on Mon Jun 12 12:06:49 2017

@author: HIMANSHU
"""
import numpy as np
from scipy.optimize import minimize

k1 = 0.5
k2 = 1

def flow_fun(p):
    return -p[6]

def cons_f1 (p):
    return np.sign(k1-p[0])*np.sqrt(np.abs(k1-p[0]))+np.sign(k1-p[1])*np.sqrt(np.abs(k1-p[1]))+np.sign(k1-p[2])*np.sqrt(np.abs(k1-p[2]))-p[6]

def cons_f2 (p):
    return np.sign(p[3]-k2)*np.sqrt(np.abs(p[3]-k2))+np.sign(p[4]-k2)*np.sqrt(np.abs(p[4]-k2))+np.sign(p[5]-k2)*np.sqrt(np.abs(p[5]-k2))-p[6]

def cons_f3 (p):
    return np.sign(p[0]-p[3])*np.sqrt(np.abs(p[0]-p[3]))+np.sign(p[1]-p[4])*np.sqrt(np.abs(p[1]-p[4]))+np.sign(p[2]-p[5])*np.sqrt(np.abs(p[2]-p[5]))-p[6]

cons = ({'type': 'eq', 'fun':cons_f1},
        {'type': 'eq', 'fun': cons_f2},
        {'type': 'eq', 'fun': cons_f3},
        {'type': 'ineq', 'fun': lambda p: np.array([p[0], p[1], p[2], p[3], p[4], p[5], 4-p[0], 4-p[1], 4-p[2], 4-p[3], 4-p[4], 4-p[5]]) } )

p0 = np.array([1,0,0,0,0,0,4])

res = minimize(flow_fun, p0, method = 'SLSQP', options= {'disp':False, 'maxiter':9000, 'ftol': 0.0}, constraints = cons)
print (res.fun)
print (res.x)
